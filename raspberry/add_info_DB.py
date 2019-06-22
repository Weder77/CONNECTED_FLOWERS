import serial, mysql.connector, time

db=mysql.connector.connect(
	host="localhost",
	user="main",
	passwd="toor!12",
	database="ConnectF"
)

cursor = db.cursor()
request = "INSERT INTO ETAT_PLANTE VALUES(NULL, %s, %s, %s, %s)"
sensorValues = serial.Serial('/dev/ttyUSB0', 9600)

while True:
	row = sensorValues.readline().split(",")
	values = (row[0],row[1],row[2],row[3])
	cursor.execute(request, values)
	db.commit()
	print("INSERT EFFECTUE")
	time.sleep(18000)


