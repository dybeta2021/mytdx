```
AMA_NUM:=12;
AMA_LONG:=30;
AMA_SHORT:=1;

DIR := ABS(C - REF(C, AMA_NUM));
VIR := SUM(ABS(C - REF(C, 1)), AMA_NUM);
ER := ABS(DIR / VIR);
FASTSC := 2 / (AMA_SHORT + 1);
SLOWSC := 2 / (AMA_LONG + 1);
SSC := ER * (FASTSC - SLOWSC) + SLOWSC;
CONSTANT := SSC * SSC;
AMV := EMA(DMA(CLOSE, CONSTANT), 3), COLORGREEN, LINETHICK3;
IF(AMV > REF(AMV, 1), AMV, DRAWNULL), COLORRED, LINETHICK4, POINTDOT;
IF(AMV > REF(AMV, 1), AMV, DRAWNULL), COLORRED, LINETHICK1;
IF(AMV = REF(AMV, 1), AMV, DRAWNULL), COLORWHITE, LINETHICK4, POINTDOT;
IF(AMV = REF(AMV, 1), AMV, DRAWNULL), COLORWHITE, LINETHICK1;
IF(AMV < REF(AMV, 1), AMV, DRAWNULL), COLORGREEN, LINETHICK1;
IF(AMV < REF(AMV, 1), AMV, DRAWNULL), COLORGREEN, LINETHICK4, POINTDOT;

DRAWICON(CROSS(AMV,REF(AMV,1)),H,1);
DRAWICON(CROSS(REF(AMV,1),AMV),L,2);

```


