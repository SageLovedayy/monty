,							read first digit from stdin and store in pos1
------------------------------------------------	convert ascii to decimal
>							move pointer to second byte
,							read from stdin and store in pos2
------------------------------------------------`	convert ascii to decimal
[							ENTER LOOP
	-						decrement pos2
	<						move pointer to pos1
	+						increment pos1
	>						move pointer to pos2
]							EXIT LOOP when last cell is empty
<							move pointer to pos1
++++++++++++++++++++++++++++++++++++++++++++++++	convert decimal to ascii
.							PRINT pos1
