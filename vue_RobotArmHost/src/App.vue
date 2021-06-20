<template>
  <div id="app">
    <!-- <ImgDraw /> -->
    <!-- <p slot="title" class="title">RobotArmHost🎨</p> -->
    <div class="title">RobotArmHost🎨</div>
    <el-container class="main">
      <el-aside id="side1" width="200px">
        <el-input v-model="mqtthost" placeholder="mqtt server"></el-input>
        <el-input v-model="mqttport" placeholder="mqtt port"></el-input>
        <el-input v-model="mqttuser" placeholder="user"></el-input>
        <el-input
          v-model="mqttpw"
          placeholder="password"
          show-password
        ></el-input>
        <el-button
          v-if="this.connected"
          class="loginBtn"
          type="danger"
          plain
          @click="closeConnection"
        >
          断开
        </el-button>
        <el-button
          v-if="!this.connected"
          class="loginBtn"
          type="success"
          plain
          @click="createConnection"
        >
          链接
        </el-button>
      </el-aside>
      <el-aside id="side2" width="150px" v-if="connected">
        <div>
          <el-button class="Btn" type="success" plain @click="robotOn"
            >启动</el-button
          >
          <div style="height: 10px"></div>
          <el-button class="Btn" type="danger" plain @click="robotOff">
            关闭
          </el-button>
          <div style="height: 10px"></div>
          <el-button class="Btn" type="warning" plain @click="clearCanvas">
            清除
          </el-button>
          <div style="height: 10px"></div>
          <el-button class="Btn" type="warning" plain @click="robotCube">
            校准
          </el-button>
        </div>
      </el-aside>
      <el-container v-if="connected">
        <el-header>
          <el-radio v-model="radio" label="1">画板</el-radio>
          <el-radio v-model="radio" label="2">备选项</el-radio>
        </el-header>
        <el-main v-if="connected">
          <div id="canvas_c" v-show="radio == '1'">
            <canvas
              id="canvas"
              :style="
                'width:' +
                canvas.width +
                'px;' +
                'height:' +
                canvas.height +
                'px;'
              "
              @mousedown="canvasDown($event)"
              @mouseup="canvasUp($event)"
              @mousemove="canvasMove($event)"
            />
          </div>
          <div v-show="radio == '1'">
            导入图片
            <input
              type="file"
              id="file"
              accept="image/*"
              @change="fileChange"
            />
            <!-- <img
              class="loadImage"
              :src="base64Img.join('')"
              alt=""
              v-show="false"
            /> -->
            <!-- base64Img是个字节数组需要拼起来才能用 -->
            <canvas id="hidecanvas" width="200" height="200" />
          </div>
        </el-main>
      </el-container>
    </el-container>
  </div>
</template>

<script>
// import ImgDraw from './components/imgDraw/imgDraw'
import mqtt from "mqtt";
import * as tool from "./tool";
import Compressor from "compressorjs";

export default {
  name: "app",
  components: {
    // ImgDraw
  },
  mounted() {
    let loadinfo = localStorage.getItem("userinfo");
    if (loadinfo) {
      let infoObj = JSON.parse(loadinfo);
      this.mqttport = infoObj.port;
      this.mqtthost = infoObj.url;
      this.mqttuser = infoObj.username;
      this.mqttpw = infoObj.password;
    }
    // this.createConnection();mounted() {
    // const canvas = document.querySelector("#canvas");
    // this.context = canvas.getContext("2d");
  },
  data() {
    return {
      radio: "1",
      connection: {
        host: "192.168.31.132",
        port: 8083,
        // endpoint: "/mqtt",
        clean: true, // 保留会话
        connectTimeout: 4000, // 超时时间
        reconnectPeriod: 4000, // 重连时间间隔
        // 认证信息
        clientId: "mqttjs_3be2c321",
        username: "admin",
        password: "public",
      },
      mqtthost: "",
      mqttport: "",
      mqttuser: "",
      mqttpw: "",
      connected: false,
      context: null,
      canvas: {
        moving: false,
        moveStep: 0,
        boxNumber: 0,
        x: 0,
        y: 0,
        width: 400,
        height: 400,
      },
      path: [],
      pointSet: {
        set: [
          [200, 100, 100],
          [200, 50, 100],
        ],
        step: 0,
      },
      // base64Img: [],
    };
  },

  methods: {
    loadCanvas() {
      if (!this.context) {
        const canvas = document.querySelector("#canvas");
        canvas.width = this.canvas.width;
        canvas.height = this.canvas.height;
        this.context = canvas.getContext("2d");
      }
    },
    genPathForPic(img) {
      this.path = [];
      this.loadCanvas();
      this.clearCanvas();
      var canvas_obj = document.getElementById("hidecanvas"); // 获取canvas标签对象
      var ctx = canvas_obj.getContext("2d"); // 设置在画布上绘图的环境
      ctx.clearRect(0, 0, canvas_obj.width, canvas_obj.height);
      // var img_obj = document.getElementById("img"); // 获取img标签对象
      ctx.drawImage(img, 0, 0); // 将图片绘制到画布上
      var imgData_obj = ctx.getImageData(0, 0, img.width, img.height); // 获取画布上的图像像素矩阵
      var imgData = imgData_obj.data; // 获取到的数据为一维数组，包含图像的RGBA四个通道数据
      console.log(imgData.length / 4);

      this.context.beginPath();
      // let last = 0;
      console.log(img.width, img.height, img);
      let opx = -1;
      let opy = -1;
      let lastUp = true;
      for (let i = 0; i < img.height; i++) {
        // this.context.moveTo(i * 5, 0);
        // this.context.moveTo(0, i * 1.5);
        if (opx > 0 && !lastUp) {
          // this.addToPath(opx, 20, opy);
        }
        // this.addToPath(0, 20, i * 1.5);
        for (let j = 0; j < img.width; j++) {
          let index = (i * img.width + j) * 4;
          let level =
            (imgData[index] + imgData[index + 1] + imgData[index + 2]) / 3;
          level = (level * 5) / 255;
          let px = j * 1.5 + 50;
          let py = i * 1.5 + 50;
          if (i % 5 > level) {
            // this.context.strokeStyle = "#2883dd";

            if (lastUp) {
              this.addToPath(px, 20, py);
              this.context.moveTo(px, py);
            } else {
              this.context.lineTo(px, py);
            }
            this.addToPath(px, 10, py);
            lastUp = false;
            // last = 1;
          } else {
            if (opx > 0) {
              // this.addToPath(opx, 20, opy);
            }
            if (!lastUp && opx > 0) {
              // this.context.moveTo(opx, opy);
              this.addToPath(opx, 20, opy);
            }

            lastUp = true;
            // last = ;
          }
          opx = px;
          opy = py;
        }
      }
      this.context.stroke();
      // for (var i = 0; i < imgData.length; i += 4) {

      //  }
      // // 将获取到的图像数据去除A通道
      // var imgArr = [];
      // for (var i = 0; i < imgData.length; i += 4) {
      //   imgArr.push(imgData[i], imgData[i + 1], imgData[i + 2]);
      // }
    },
    fileChange(e) {
      let file = e.target.files[0];
      let that = this;
      new Compressor(file, {
        maxWidth: 200,
        maxHeight: 200,
        success(result) {
          console.log(result);
          let reader = new FileReader();

          reader.onload = function () // value
          {
            // that.base64Img.push(value.target.result);
            tool.blobToImage(result, (img) => {
              that.genPathForPic(img);
            });
            // this.resizeMe();
          };
          reader.readAsDataURL(result);
        },
      });

      // let reader = new FileReader();
      // let that = this;
      // reader.onload = function (value) {
      //   that.base64Img.push(value.target.result);
      //   this.resizeMe();
      // };
      // reader.readAsDataURL(file);
    },
    addToPath(ox, oy, oz) {
      ox /= 4;

      oz /= 4;
      // oy /= 2;
      // oz /= 2;
      // oz-=100;
      oz += 100;
      // o-=100;
      // ox += 50;
      ox = ox - 50;
      ox = -ox;
      // console.log("after", oz, oy, ox);
      this.path.push([oz, oy, ox]);
    },
    canvasDown(e) {
      console.log(e);
      if (!this.context) {
        const canvas = document.querySelector("#canvas");
        canvas.width = this.canvas.width;
        canvas.height = this.canvas.height;
        this.context = canvas.getContext("2d");
      }
      // reset
      this.canvas.moving = true; // 是否是在绘制
      this.canvas.moveStep = 0;
      this.canvas.boxNumber++;

      const { target } = e;

      // 获取鼠标初始位置
      const canvasX = e.clientX - target.offsetLeft;
      const canvasY = e.clientY - target.offsetTop;
      // 初始位置赋值给全局
      this.canvas.x = canvasX;
      this.canvas.y = canvasY;

      this.context.beginPath();

      this.context.moveTo(canvasX, canvasY);
      // if(this.path.length>0){
      this.addToPath(canvasX, 20, canvasY);
      // }
      this.addToPath(canvasX, 10, canvasY);
      // this.tempImgData = this.context.getImageData(0, 0, 100, 100); // 记录暂时图像
    },
    canvasMove(e) {
      // console.log(this.canvas);
      if (this.canvas.moving) {
        const { target } = e;
        // 获取鼠标位置
        const canvasX = e.clientX - target.offsetLeft;
        const canvasY = e.clientY - target.offsetTop;
        // 获取初始位置
        // const { x, y } = this.rectPos;
        // let x = this.canvas.x;
        // let y = this.canvas.y;
        let dx = this.canvas.x - canvasX;
        let dy = this.canvas.y - canvasY;
        if (Math.sqrt(dx * dx + dy * dy) > 5) {
          this.context.fillStyle = "#2883dd";
          this.context.lineTo(canvasX, canvasY);
          this.context.stroke();
          this.context.fillStyle = "#000";
          this.canvas.x = canvasX;
          this.canvas.y = canvasY;
          this.addToPath(canvasX, 10, canvasY);

          console.log(canvasX, canvasY);
        }
      }
    },
    canvasUp(e) {
      const { target } = e;
      // 获取鼠标位置
      const canvasX = e.clientX - target.offsetLeft;
      const canvasY = e.clientY - target.offsetTop;
      this.addToPath(canvasX, 20, canvasY);
      console.log(e);
      // const { target } = e;
      // // 获取鼠标结束位置
      // const canvasX = e.clientX - target.offsetLeft;
      // const canvasY = e.clientY - target.offsetTop;
      // // 获取初始位置
      // const { x, y } = this.rectPos;
      // if (this.moving) {
      //   this.context.fillStyle = "#2883dd";
      //   this.context.strokeRect(x, y, canvasX - x, canvasY - y);
      //   this.context.fillStyle = "#000";
      //   this.context.fillRect(x, y, canvasX - x, canvasY - y);
      // }

      // this.context.closePath();
      this.canvas.moving = false;
    },
    clearCanvas() {
      this.context.clearRect(0, 0, this.canvas.width, this.canvas.height);
      this.path = [];
      // let arr = new Uint8Array(2);
      // arr[0] = 2;
      // arr[1] = 4;
      // var data = new Float32Array([200, 100, 100]);

      // // var buffer = new ArrayBuffer(data.byteLength);
      // // // var floatView = new Float32Array(buffer).set(data);
      // // var byteView = new Uint8Array(buffer);
      // let byteView = tool.convertTypedArray(data, Uint8Array);
      // var mergedArray = new Uint8Array(arr.length + byteView.length);
      // mergedArray.set(arr);
      // mergedArray.set(byteView, arr.length);
      // this.client.publish("/topic/qos0", mergedArray, 0, (error) => {
      //   if (error) {
      //     console.log("Publish error", error);
      //   }
      // });
    },
    robotOn() {
      let arr = new Uint8Array(2);
      arr[0] = 2;
      arr[1] = 2;
      this.client.publish("/topic/qos0", arr, 0, (error) => {
        if (error) {
          console.log("Publish error", error);
        }
      });
    },
    robotOff() {
      let arr = new Uint8Array(2);
      arr[0] = 2;
      arr[1] = 3;
      this.client.publish("/topic/qos0", arr, 0, (error) => {
        if (error) {
          console.log("Publish error", error);
        }
      });
    },
    robotCube() {
      this.addToPath(50, 20, 50);
      this.addToPath(50, 10, 50);
      this.addToPath(50, 10, 350);
      this.addToPath(350, 10, 350);
      this.addToPath(350, 10, 50);
      this.addToPath(350, 20, 50);
    },
    closeConnection() {
      this.client.end();

      let that = this;
      this.client.on("end", () => {
        that.connected = false;
        // this.connected = true;
      });
    },
    // 创建连接
    createConnection() {
      // 连接字符串, 通过协议指定使用的连接方式
      // ws 未加密 WebSocket 连接
      // wss 加密 WebSocket 连接
      // mqtt 未加密 TCP 连接
      // mqtts 加密 TCP 连接
      // wxs 微信小程序连接
      // alis 支付宝小程序连接
      if (this.client && this.client.connected) {
        this.connected = true;
        return;
      }
      if (!this.connected) {
        const { host, port, ...options } = this.connection;
        console.log(host, port);
        const connectUrl = `ws://${this.mqtthost}:${this.mqttport}/mqtt`;
        options.username = this.mqttuser;
        options.password = this.mqttpw;
        try {
          this.client = mqtt.connect(connectUrl, options);
        } catch (error) {
          console.log("mqtt.connect error", error);
        }
        let that = this;
        this.client.on("connect", () => {
          console.log("Connection succeeded!");
          localStorage.setItem(
            "userinfo",
            JSON.stringify({
              username: options.username,
              password: options.password,
              url: that.mqtthost,
              port: that.mqttport,
            })
          );
          that.connected = true;
          that.client.subscribe("/topic/slave", 0, (error) => {
            if (error) {
              console.log("Subscribe to topics error", error);
              // return;
            }
            // this.subscribeSuccess = true;
            // console.log("Subscribe to topics res", res);
          });
          // this.connected = true;
        });
        this.client.on("error", (error) => {
          console.log("Connection failed", error);
        });
        this.client.on("message", (topic, message) => {
          // console.log(topic, message);
          // this.receiveNews = this.receiveNews.concat(message);
          console.log(`Received message ${message} from topic ${topic}`);
          if (this.path.length >= 1) {
            console.log(this.path.length);
            if (topic == "/topic/slave") {
              if (message == "sos") {
                let arr = new Uint8Array(3);
                arr[0] = 2;
                arr[1] = 4;
                if (this.path.length >= 5) {
                  arr[2] = 5;
                } else {
                  arr[2] = this.path.length;
                }
                let byteViews = [];
                let sumLen = 3;
                for (let i = 0; i < arr[2]; i++) {
                  var data = new Float32Array(
                    this.path[0]
                    // this.pointSet.set[
                    //   this.pointSet.step % this.pointSet.set.length
                    // ]
                  );
                  this.path.shift();
                  // this.pointSet.step++;
                  byteViews.push(tool.convertTypedArray(data, Uint8Array));
                  sumLen += byteViews[byteViews.length - 1].length;
                }

                // var buffer = new ArrayBuffer(data.byteLength);
                // // var floatView = new Float32Array(buffer).set(data);
                // var byteView = new Uint8Array(buffer);
                var mergedArray = new Uint8Array(sumLen);
                mergedArray.set(arr);
                let offset = arr.length;
                for (let i = 0; i < arr[2]; i++) {
                  mergedArray.set(byteViews[i], offset);
                  offset += byteViews[i].length;
                }
                this.client.publish("/topic/qos0", mergedArray, 0, (error) => {
                  if (error) {
                    console.log("Publish error", error);
                  }
                });
                that.pointSet;
              }
            }
          }
        });
      }
    },
  },
};
</script>

<style>
#app {
  font-family: "Avenir", Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin: 0;
  padding: 0;
  /* padding-top: 60px; */
  /* height: 100vh; */
  /* margin-top: 60px; */
}
body {
  margin: 0;
}
.el-header,
.el-footer {
  background-color: #b3c0d1;
  color: #333;
  text-align: center;
  line-height: 60px;
}

#side1 {
  padding: 10px;
  /* padding-bottom: 0; */
  background-color: #bfc8d3;
  color: #333;

  /* height: 100%; */
  /* text-align: center; */
  /* line-height: 200px; */
}
#side2 {
  padding: 10px;
  /* padding-bottom: 0; */
  background-color: #d3dce6;
  color: #333;

  /* height: 100%; */
  /* text-align: center; */
  /* line-height: 200px; */
}
.el-main {
  background-color: #e9eef3;
  color: #333;
  /* text-align: center; */
  /* line-height: 160px; */
}
.el-input {
  padding-bottom: 10px;
}
.loginBtn {
  width: 100%;
}
.title {
  top: 0;
  width: 100%;
  height: 60px;
  position: fixed;
  text-align: center;
  line-height: 60px;
  /* padding-top: 20px; */
  /* padding: 20px; */
}
.main {
  padding-top: 60px;
  height: 100vh;
}
/* .el-container {
  padding-top: 60px;
} */

.Btn {
  /* padding: 0; */
  width: 100%;
  margin-bottom: 10px;
}
#canvas {
  /* width: 100px; */
  /* height: 100px; */
  border: 1px black solid;
}
.loadImage {
  width: 400px;
  /* height: 400px; */
}
/*#canvas_c {
  width: 200px;
  height: 200px;
  border: 1px black solid;
} */
/* .controlPanel{
  width: 100%;
  height: 100%;
} */
</style>
