```
LC:=REF(CLOSE,1);
RSI14:SMA(MAX(CLOSE-LC,0),14,1)/SMA(ABS(CLOSE-LC),14,1)*100;
U:70;
M:50;
D:30;

DRAWICON(CROSS(RSI14,20), RSI14, 1);
DRAWICON(CROSS(80, RSI14), RSI14, 2);
```


