# Communication Protocols
## SERVICE LIST
`CHARACTER_COUNT`: Return the number of characters from string <br>
`WORD_COUNT`: Return the number of words from string <br>
`REVERSE_STRING`: Return reversed string <br>
`STRING_WITHOUT_VOWELS`: Return string without vowels <br>
`DETERMINAN_AND_INVERSE_MATRIX`: Return determinan and inverse of matrix <br>

## Service Availability Checks
Client Request
```text
CHECK $SERVICE_NAME
```

Server Response
```text
CHECK $RESULT
```
`$RESULT`:  `ACTIVE` or `INACTIVE` <br>

## SERVICE REQUEST
### CHARACTER_COUNT
Client
```text
REQUEST $SERVICE_NAME $TEXT
```

Server
```text
RESPONSE $NUM
```

### WORD_COUNT
Client
```text
REQUEST $SERVICE_NAME $TEXT
```

Server
```text
RESPONSE $NUM
```

### REVERSE_STRING
Client
```text
REQUEST $SERVICE_NAME $TEXT
```

Server
```text
RESPONSE $REVERSED_TEXT
```

### STRING_WITHOUT_VOWELS
Client
```text
REQUEST $SERVICE_NAME $TEXT
```

Server
```text
RESPONSE $TEXT_WITHOUT_VOWELS
```

### DETERMINAN_AND_INVERSE_MATRIX
Client
```text
REQUEST $SERVICE_NAME $a[0][0] $a[0][1] $a[0][2] $a[1][0] $a[1][1] $a[1][2] $a[2][0] $a[2][1] $a[2][2]
```

Server
```text
RESPONSE $DETERMINAN $a[0][0] $a[0][1] $a[0][2] $a[1][0] $a[1][1] $a[1][2] $a[2][0] $a[2][1] $a[2][2]
```

## ACKNOWLEDGEMENT
Client
```text
ACK $RESULT
```
`$RESULT`:  `TRUE` or `FALSE` <br>
Server
```text
OK
```

## SERVER ERROR
Server
```text
ERROR $ERROR_MESSAGE
```