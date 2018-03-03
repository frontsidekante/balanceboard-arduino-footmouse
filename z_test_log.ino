//author: frontsidekante
//functions used for logging values

void printRawMotion6(){

  Serial.print("| RawAccX: ");
  Serial.print(RawAccX);
  Serial.print("| RawAccY: ");
  Serial.print(RawAccY);
  Serial.print("| RawAccZ: ");
  Serial.print(RawAccZ);
  Serial.print("| RawGyroX: ");
  Serial.print(RawGyroX);
  Serial.print("| RawGyroY: ");
  Serial.print(RawGyroY);
  Serial.print("| RawGyroZ:  ");
  Serial.println(RawGyroZ);
  delay(200); 
}

void printUsableGyroData(){
  
  Serial.print(" | GyroX: ");
  Serial.print(usableGyroX);
  Serial.print(" | GyroY: ");
  Serial.print(usableGyroY);
  Serial.print(" | GyroZ: ");
  Serial.println(usableGyroZ);
  delay(200); 
}

void printUsableAccData(){

  Serial.print(" | AccX: ");
  Serial.print(usableAccX);
  Serial.print(" | AccY: ");
  Serial.print(usableAccY);
  Serial.print(" | AccZ: ");
  Serial.println(usableAccZ);
  delay(200);  
}


  
