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
func RecalcPointSlice(){
	trackPointSliceLen:=calcPointSliceLen()
	trackPointSlice=make([]armStatePoint, trackPointSliceLen)

	minSectionXLen:=armDesc.minSectionLen/sqrt2
	//curXstep:=minSectionXLen
	var curStepCnt1 int32=0
	//var sectionCnt1 int32=0

	for{
		var curXLen float32 =minSectionXLen + armDesc.penWidth*float32(curStepCnt1)
		curSectionCnt:=int32(curXLen/minSectionXLen)
		var j int32=0
		var (
			px float32
			py float32
		)
		for ;j<curSectionCnt+1;j++{
			py=float32(j)*curXLen/float32(curSectionCnt)
			px=curXLen-py
			if curStepCnt1%2==0 {//偶数正向
				trackPointSlice[j].position.x=armDesc.armOriginalPointX+ px//这里坐标换算还得修改。
				trackPointSlice[j].position.y=armDesc.armOriginalPointY- py
			}else{//奇数反向
				trackPointSlice[j].position.x=armDesc.armOriginalPointX+ py
				trackPointSlice[j].position.y=armDesc.armOriginalPointY - px
			}
		}

		//curXstep+=armDesc.penWidth
		curStepCnt1++
		if curXLen > armDesc.paperWidth{
			break
		}
	}
}







