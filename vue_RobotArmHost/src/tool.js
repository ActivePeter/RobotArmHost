export function convertTypedArray(src, type) {
    var buffer = new ArrayBuffer(src.byteLength);
    new src.constructor(buffer).set(src);
    return new type(buffer);
}

// canvas转dataURL：canvas对象、转换格式、图像品质
export function canvasToDataURL(canvas, format, quality) {
    return canvas.toDataURL(format || 'image/jpeg', quality || 1.0);
}


// DataURL转canvas
export function dataURLToCanvas(dataurl, cb) {
    var canvas = document.createElement('CANVAS');
    var ctx = canvas.getContext('2d');
    var img = new Image();
    img.onload = function () {
        canvas.width = img.width;
        canvas.height = img.height;
        ctx.drawImage(img, 0, 0);
        cb(canvas);
    };
    img.src = dataurl;
}

// image转canvas：图片地址
export function imageToCanvas(src, cb) {
    var canvas = document.createElement('CANVAS');
    var ctx = canvas.getContext('2d');
    var img = new Image();
    img.src = src;
    img.onload = function () {
        canvas.width = img.width;
        canvas.height = img.height;
        ctx.drawImage(img, 0, 0);
        cb(canvas);
    };
}

// canvas转image
export function canvasToImage(canvas) {
    var img = new Image();
    img.src = canvas.toDataURL('image/jpeg', 1.0);
    return img;
}

// File/Blob对象转DataURL
export function fileOrBlobToDataURL(obj, cb) {
    var a = new FileReader();
    a.readAsDataURL(obj);
    a.onload = function (e) {
        cb(e.target.result);
    };
}
// DataURL转Blob对象
export function dataURLToBlob(dataurl) {
    var arr = dataurl.split(',');
    var mime = arr[0].match(/:(.*?);/)[1];
    var bstr = atob(arr[1]);
    var n = bstr.length;
    var u8arr = new Uint8Array(n);
    while (n--) {
        u8arr[n] = bstr.charCodeAt(n);
    }
    return new Blob([u8arr], { type: mime });
}
// Blob转image
export function blobToImage(blob, cb) {
    fileOrBlobToDataURL(blob, function (dataurl) {
        var img = new Image();
        img.src = dataurl;
        img.onload = function () {

            cb(img);

        }
    });
}
// image转Blob
export function imageToBlob(src, cb) {
    imageToCanvas(src, function (canvas) {
        cb(dataURLToBlob(canvasToDataURL(canvas)));
    });
}
// Blob转canvas
export function BlobToCanvas(blob, cb) {
    fileOrBlobToDataURL(blob, function (dataurl) {
        dataURLToCanvas(dataurl, cb);
    });
}
// canvas转Blob
export function canvasToBlob(canvas, cb) {
    cb(dataURLToBlob(canvasToDataURL(canvas)));
}
// image转dataURL
export function imageToDataURL(src, cb) {
    imageToCanvas(src, function (canvas) {
        cb(canvasToDataURL(canvas));
    });
}
// dataURL转image，这个不需要转，直接给了src就能用
export function dataURLToImage(dataurl) {
    var img = new Image();
    img.src = dataurl;
    return img;
}