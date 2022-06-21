//-- CONSTANTES

//-- Distribucion de pines
//-- Pines salidas digitales
#define PIN_LED            A0
#define PIN_DRIVE_VCC       A2
#define PIN_ALARMA1         5
#define PIN_ALARMA2         6
#define RFM95_RST         2
//-- Pines de sensores
#define PIN_SENSOR1         7
#define PIN_SENSOR2         8
#define PIN_SENSOR3         9
//-- Pines SPI LoRa
#define RFM95_CS          10
#define RFM95_INT         3
//      MOSI            11
//      MISO            12
//      SCK             13

//-- Constantes LoRa      
#define longMensaje         200
#define RF95_FREQ         915.0

//#define CICLOS_AHORRO_ENERGIA_8S  112 
#define CICLOS_AHORRO_ENERGIA_8S  2

#define SONDA_1           1
#define SONDA_2           2
#define SONDA_3           3

#define INTENTOS_MEDICION     5

#define B_MAX           3300
#define B_MIN           2800


//-- VARIABLES
bool errorSonda1 = false;
bool errorSonda2 = false;
bool errorSonda3 = false;

bool errorMedidaSonda1 = false;
bool errorMedidaSonda2 = false;
bool errorMedidaSonda3 = false;

bool okEnvio = false;
bool okReciboAck = false;

String data;

bool enviadoOk = false;
