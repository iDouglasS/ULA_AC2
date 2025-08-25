int resultado = 0;
int entradaX = 0;
int entradaY = 0;
int entradaOpCode = 0;

String memoria[100];
int cont = 4;
String pc = memoria[cont];
String w = memoria[1];
String x = memoria[2];
String y = memoria[3];
String entrada;
String resultadoC;




const int ledAzul = 10;
const int ledVermelho = 13;
const int ledVerde = 11;
const int ledAmarelo = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    entrada = Serial.readStringUntil('\n'); 
    dividirString(entrada, memoria, cont); 
    

    for (int i = 4; i <= cont; i++) {
      
      Serial.print(i);
      Serial.print(" ");
      
      memoria[2] = memoria[i].substring(0, 1);
      entradaX = hexToDec(memoria[2].charAt(0));
      
      memoria[3] = memoria[i].substring(1, 2);
      entradaY = hexToDec(memoria[3].charAt(0));
      
      entradaOpCode = hexToDec(memoria[i].substring(2,3).charAt(0));
      
      resultado = Ula(entradaX,
                      entradaY, 
                      entradaOpCode);
      ligarLed(resultado);

      resultadoC = decToHex(resultado);
      
   	 
      String s = resultadoC+ " "+ 
        		memoria[2] + " " + 
        		memoria[3]+" ";  
      Serial.print(s);
      for(int j=4; j<=i; j++){
        Serial.print(memoria[j] + " ");
      }
      Serial.println();
      delay(5000);
    }
  }
}

void dividirString(String entrada, String vetor[], int &cont) {
  int posicao;
  while (entrada.length() > 0 && cont < 95) {
    posicao = entrada.indexOf(' ');  
    if (posicao == -1) {
      vetor[cont] = entrada;  
      break;
    }
    vetor[cont] = entrada.substring(0, posicao);
    entrada = entrada.substring(posicao + 1);  
    cont++;
  }
}
int Ula(int a, int b, int opcode) {
    switch (opcode) {
        case 0x0: return 0;break;      
        case 0x1: return 15;break;      
        case 0x2: return a;break;        
        case 0x3: return b;break;        
        case 0x4: return ~a & 0xF;break;   
        case 0x5: return ~b & 0xF;break;   
        case 0x6: return a & (~b) & 0xF;break;   
        case 0x7: return (~a & b) & 0xF;break;   
        case 0x8: return (a ^ b) & 0xF;break;   
        case 0x9: return (~a ^ ~b) & 0xF;break;   
        case 0xA: return ~(~a ^ ~b) & 0xF;break;   
        case 0xB: return (a & b) & 0xF;break;  
        case 0xC: return (~(a & b)) & 0xF;break;  
        case 0xD: return (~(a | b)) & 0xF;break;   
        case 0xE: return (a | b) & 0xF;break;   
        case 0xF: return ~(~a | ~b) & 0xF;break;  
        default: return 0;
      
    }
}

int hexToDec(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return 0;
}
String decToHex(int decimal) {
  String hexString = "";  
  char hexDigits[] = "0123456789ABCDEF";
  
  if (decimal == 0) {
    return "0";
  }
  
  while (decimal > 0) {
    int resto = decimal % 16;  
    hexString = hexDigits[resto] + hexString; 
    decimal = decimal / 16;
  }
  
  return hexString; 
}

void ligarLed(int x){
        switch (x){
        
        case 0:
          		digitalWrite(ledVermelho, LOW);
				digitalWrite(ledVerde, LOW);
				digitalWrite(ledAmarelo, LOW);
        		digitalWrite(ledAzul, LOW);
          break;
        case 1:  
          digitalWrite(ledVermelho, LOW);
				digitalWrite(ledVerde, LOW);
				digitalWrite(ledAmarelo, LOW);
        		digitalWrite(ledAzul, HIGH);
          break;
        case 2:     
          digitalWrite(ledVermelho, LOW);
				digitalWrite(ledVerde, HIGH);
				digitalWrite(ledAmarelo, LOW);
        		digitalWrite(ledAzul, LOW);
          break;
        case 3:   
          digitalWrite(ledVermelho, LOW);
				digitalWrite(ledVerde, HIGH);
				digitalWrite(ledAmarelo, LOW);
        		digitalWrite(ledAzul, HIGH);
          break;
        case 4:
          digitalWrite(ledVermelho, LOW);
				digitalWrite(ledVerde, LOW);
				digitalWrite(ledAmarelo, HIGH);
        		digitalWrite(ledAzul, LOW);
          break;
        case 5:
          digitalWrite(ledVermelho, LOW);
				digitalWrite(ledVerde, LOW);
				digitalWrite(ledAmarelo, HIGH);
        		digitalWrite(ledAzul, HIGH);
          break;
        case 6:
          digitalWrite(ledVermelho, LOW);
				digitalWrite(ledVerde, HIGH);
				digitalWrite(ledAmarelo, HIGH);
        		digitalWrite(ledAzul, LOW);
          break;
        case 7:
          digitalWrite(ledVermelho, LOW);
				digitalWrite(ledVerde, HIGH);
				digitalWrite(ledAmarelo, HIGH);
        		digitalWrite(ledAzul, HIGH);
          break;
        case 8:
          digitalWrite(ledVermelho, HIGH);
				digitalWrite(ledVerde, LOW);
				digitalWrite(ledAmarelo, LOW);
        		digitalWrite(ledAzul, LOW);
          break;
        case 9:
          digitalWrite(ledVermelho, HIGH);
				digitalWrite(ledVerde, LOW);
				digitalWrite(ledAmarelo, LOW);
        		digitalWrite(ledAzul, HIGH);
          break;
        case 10:
          digitalWrite(ledVermelho, HIGH);
				digitalWrite(ledVerde, HIGH);
				digitalWrite(ledAmarelo, LOW);
        		digitalWrite(ledAzul, LOW);
          break;
        case 11:
          digitalWrite(ledVermelho, HIGH);
				digitalWrite(ledVerde, HIGH);
				digitalWrite(ledAmarelo, LOW);
        		digitalWrite(ledAzul, HIGH);
          break;
        case 12:
          digitalWrite(ledVermelho, HIGH);
				digitalWrite(ledVerde, LOW);
				digitalWrite(ledAmarelo, HIGH);
        		digitalWrite(ledAzul, LOW);
          break;
        case 13:
          digitalWrite(ledVermelho, HIGH);
				digitalWrite(ledVerde, LOW);
				digitalWrite(ledAmarelo, HIGH);
        		digitalWrite(ledAzul, HIGH);
          break;
        case 14:
          digitalWrite(ledVermelho, HIGH);
				digitalWrite(ledVerde, HIGH);
				digitalWrite(ledAmarelo, HIGH);
        		digitalWrite(ledAzul, LOW);
          break;
        case 15:
          digitalWrite(ledVermelho, HIGH);
				digitalWrite(ledVerde, HIGH);
				digitalWrite(ledAmarelo, HIGH);
        		digitalWrite(ledAzul, HIGH);
          break;
        default:digitalWrite(ledVermelho, LOW);
				digitalWrite(ledVerde, LOW);
				digitalWrite(ledAmarelo, LOW);
        		digitalWrite(ledAzul, LOW);
          break;
      }
}