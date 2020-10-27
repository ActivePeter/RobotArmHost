package PathBuilder

const sqrt2 = 1.4142135623731//根号2

type point struct {
	x float32
	y float32
}

type armStatePoint struct {
	position point//当前坐标
	state int8//抬起或放下
}

type description struct{
	paperWidth float32
	paperHeight float32
	armOriginalPointX float32
	armOriginalPointY float32
	penWidth float32
	minSectionLen float32
}

var (
	curStepCnt int32 = 0
	curSectionCnt int32 =0


	sectionLen float32 = 0

	armDesc =&description{//单位mm
		200,200,100,200,0.5,2,
	}
	trackPointSlice []armStatePoint
)
func calcSectionCnt() int32{
	minSectionXLen:=armDesc.minSectionLen/sqrt2
	//curXstep:=minSectionXLen
	var curStepCnt1 int32=0
	var sectionCnt1 int32=0

	for{
		var curXLen float32 =minSectionXLen + armDesc.penWidth*float32(curStepCnt1)
		sectionCnt1+=int32(curXLen/minSectionXLen)
		//curXstep+=armDesc.penWidth
		curStepCnt1++
		if curXLen > armDesc.paperWidth{
			break
		}
	}
	return sectionCnt1
}
func calcPointSliceLen() int32{
	return calcSectionCnt()+1
}
func initPointSlice(){
	trackPointSliceLen:=calcPointSliceLen()
	trackPointSlice=make([]armStatePoint, trackPointSliceLen)

	minSectionXLen:=armDesc.minSectionLen/sqrt2
	//curXstep:=minSectionXLen
	var curStepCnt1 int32=0
	//var sectionCnt1 int32=0

	for{
		var curXLen float32 =minSectionXLen + armDesc.penWidth*float32(curStepCnt1)
		curSectionCnt:=int32(curXLen/minSectionXLen)
		if curStepCnt1%2==0 {//偶数正向

		}else{//奇数反向

		}
		//curXstep+=armDesc.penWidth
		curStepCnt1++
		if curXLen > armDesc.paperWidth{
			break
		}
	}
}







