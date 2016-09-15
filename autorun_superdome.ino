
void setup_autorun_superdome(void)
{
#if DEBUG
  debug("Setup for 128-LED SuperDome\r\n");
#endif

//Quarter A  
  AUTORUN_LEDS[0][0] = 1; //1
  AUTORUN_LEDS[0][1] = 8;
  AUTORUN_LEDS[0][2] = 0; 
  AUTORUN_LEDS[1][0] = 1; //2
  AUTORUN_LEDS[1][1] = 128;
  AUTORUN_LEDS[1][2] = 0;
  AUTORUN_LEDS[2][0] = 2; //3
  AUTORUN_LEDS[2][1] = 128;
  AUTORUN_LEDS[2][2] = 0;
  AUTORUN_LEDS[3][0] = 4;  //4
  AUTORUN_LEDS[3][1] = 128;
  AUTORUN_LEDS[3][2] = 0;
  AUTORUN_LEDS[4][0] = 8;  //5
  AUTORUN_LEDS[4][1] = 128;
  AUTORUN_LEDS[4][2] = 0;
  AUTORUN_LEDS[5][0] = 1;  //6
  AUTORUN_LEDS[5][1] = 16;
  AUTORUN_LEDS[5][2] = 0;
  AUTORUN_LEDS[6][0] = 1;  //7
  AUTORUN_LEDS[6][1] = 64;
  AUTORUN_LEDS[6][2] = 0;
  AUTORUN_LEDS[7][0] = 2;  //8
  AUTORUN_LEDS[7][1] = 64;
  AUTORUN_LEDS[7][2] = 0;
  AUTORUN_LEDS[8][0] = 4;  //9
  AUTORUN_LEDS[8][1] = 64;  
  AUTORUN_LEDS[8][2] = 0;
  AUTORUN_LEDS[9][0] = 8;  //10  
  AUTORUN_LEDS[9][1] = 64;
  AUTORUN_LEDS[9][2] = 0;  
  AUTORUN_LEDS[10][0] = 1;  //11
  AUTORUN_LEDS[10][1] = 32;  
  AUTORUN_LEDS[10][2] = 0;
  AUTORUN_LEDS[11][0] = 2;  //12
  AUTORUN_LEDS[11][1] = 32;
  AUTORUN_LEDS[11][2] = 0;  
  AUTORUN_LEDS[12][0] = 4;  //13
  AUTORUN_LEDS[12][1] = 32;  
  AUTORUN_LEDS[12][2] = 0;
  AUTORUN_LEDS[13][0] = 8;  //14
  AUTORUN_LEDS[13][1] = 32;
  AUTORUN_LEDS[13][2] = 0;  
  AUTORUN_LEDS[14][0] = 2;  //15
  AUTORUN_LEDS[14][1] = 16; 
  AUTORUN_LEDS[14][2] = 0;
  AUTORUN_LEDS[15][0] = 4;  //16
  AUTORUN_LEDS[15][1] = 16;
  AUTORUN_LEDS[15][2] = 0;
  AUTORUN_LEDS[16][0] = 8;  //17
  AUTORUN_LEDS[16][1] = 16;
  AUTORUN_LEDS[16][2] = 0;
  AUTORUN_LEDS[17][0] = 4;  //18
  AUTORUN_LEDS[17][1] = 8;
  AUTORUN_LEDS[17][2] = 0;
  AUTORUN_LEDS[18][0] = 8;   //19
  AUTORUN_LEDS[18][1] = 8;
  AUTORUN_LEDS[18][2] = 0;
  AUTORUN_LEDS[19][0] = 16;  //1
  AUTORUN_LEDS[19][1] = 8;
  AUTORUN_LEDS[19][2] = 0;
  AUTORUN_LEDS[20][0] = 16;  //2
  AUTORUN_LEDS[20][1] = 128;
  AUTORUN_LEDS[20][2] = 0;
  AUTORUN_LEDS[21][0] = 32;  //3
  AUTORUN_LEDS[21][1] = 128;
  AUTORUN_LEDS[21][2] = 0;
  AUTORUN_LEDS[22][0] = 64;  //4
  AUTORUN_LEDS[22][1] = 128;
  AUTORUN_LEDS[22][2] = 0;
  AUTORUN_LEDS[23][0] = 128;  //5
  AUTORUN_LEDS[23][1] = 128;
  AUTORUN_LEDS[23][2] = 0;
  AUTORUN_LEDS[24][0] = 16;  //6
  AUTORUN_LEDS[24][1] = 16;
  AUTORUN_LEDS[24][2] = 0;
  AUTORUN_LEDS[25][0] = 16;  //7
  AUTORUN_LEDS[25][1] = 64;
  AUTORUN_LEDS[25][2] = 0;
  AUTORUN_LEDS[26][0] = 32;  //8
  AUTORUN_LEDS[26][1] = 64;
  AUTORUN_LEDS[26][2] = 0;
  AUTORUN_LEDS[27][0] = 64;  //9
  AUTORUN_LEDS[27][1] = 64;
  AUTORUN_LEDS[27][2] = 0;
  AUTORUN_LEDS[28][0] = 128;  //10
  AUTORUN_LEDS[28][1] = 64;
  AUTORUN_LEDS[28][2] = 0;
  AUTORUN_LEDS[29][0] = 16;  //11
  AUTORUN_LEDS[29][1] = 32;
  AUTORUN_LEDS[29][2] = 0;
  AUTORUN_LEDS[30][0] = 32;  //12
  AUTORUN_LEDS[30][1] = 32;
  AUTORUN_LEDS[30][2] = 0;
  AUTORUN_LEDS[31][0] = 64;  //13
  AUTORUN_LEDS[31][1] = 32;
  AUTORUN_LEDS[31][2] = 0;

//Quarter B
  AUTORUN_LEDS[32][0] = 128;  //14
  AUTORUN_LEDS[32][1] = 32;
  AUTORUN_LEDS[32][2] = 0;
  AUTORUN_LEDS[33][0] = 32;  //15
  AUTORUN_LEDS[33][1] = 16;
  AUTORUN_LEDS[33][2] = 0;
  AUTORUN_LEDS[34][0] = 64;  //16
  AUTORUN_LEDS[34][1] = 16;
  AUTORUN_LEDS[34][2] = 0;
  AUTORUN_LEDS[35][0] = 128;  //17
  AUTORUN_LEDS[35][1] = 16;
  AUTORUN_LEDS[35][2] = 0;
  AUTORUN_LEDS[36][0] = 64;  //18
  AUTORUN_LEDS[36][1] = 8;
  AUTORUN_LEDS[36][2] = 0;
  AUTORUN_LEDS[37][0] = 128;  //19
  AUTORUN_LEDS[37][1] = 8;
  AUTORUN_LEDS[37][2] = 0;
  AUTORUN_LEDS[38][0] = 0;  //1
  AUTORUN_LEDS[38][1]= 8;
  AUTORUN_LEDS[38][2] = 1;
  AUTORUN_LEDS[39][0] = 0;  //2
  AUTORUN_LEDS[39][1] = 128;
  AUTORUN_LEDS[39][2] = 1;
  AUTORUN_LEDS[40][0] = 0;  //3
  AUTORUN_LEDS[40][1] = 128;
  AUTORUN_LEDS[40][2] = 2;
  AUTORUN_LEDS[41][0] = 0;  //4
  AUTORUN_LEDS[41][1] = 128;
  AUTORUN_LEDS[41][2] = 4;
  AUTORUN_LEDS[42][0] = 0;  //5
  AUTORUN_LEDS[42][1] = 128;
  AUTORUN_LEDS[42][2] = 8;
  AUTORUN_LEDS[43][0] = 0;  //6
  AUTORUN_LEDS[43][1] = 16;
  AUTORUN_LEDS[43][2] = 1;
  AUTORUN_LEDS[44][0] = 0;  //7
  AUTORUN_LEDS[44][1] = 64;
  AUTORUN_LEDS[44][2] = 1;
  AUTORUN_LEDS[45][0] = 0;  //8
  AUTORUN_LEDS[45][1] = 64;
  AUTORUN_LEDS[45][2] = 2;
  AUTORUN_LEDS[46][0] = 0;  //9
  AUTORUN_LEDS[46][1] = 64;
  AUTORUN_LEDS[46][2] = 4;
  AUTORUN_LEDS[47][0] = 0;  //10
  AUTORUN_LEDS[47][1] = 64;
  AUTORUN_LEDS[47][2] = 8;
  AUTORUN_LEDS[48][0] = 0;  //11
  AUTORUN_LEDS[48][1] = 32;
  AUTORUN_LEDS[48][2] = 1;
  AUTORUN_LEDS[59][0] = 0;  //12
  AUTORUN_LEDS[49][1] = 32;
  AUTORUN_LEDS[49][2] = 2;
  AUTORUN_LEDS[50][0] = 0;  //13
  AUTORUN_LEDS[50][1] = 32;
  AUTORUN_LEDS[50][2] = 4;
  AUTORUN_LEDS[51][0] = 0;  //14
  AUTORUN_LEDS[51][1] = 32;
  AUTORUN_LEDS[51][2] = 8;
  AUTORUN_LEDS[52][0] = 0;   //15
  AUTORUN_LEDS[52][1] = 16;
  AUTORUN_LEDS[52][2] = 2;
  AUTORUN_LEDS[53][0] = 0;  //16
  AUTORUN_LEDS[53][1] = 16;
  AUTORUN_LEDS[53][2] = 4;
  AUTORUN_LEDS[54][0] = 0;  //17
  AUTORUN_LEDS[54][1] = 16;
  AUTORUN_LEDS[54][2] = 8;
  AUTORUN_LEDS[55][0] = 0;  //18
  AUTORUN_LEDS[55][1] = 8;
  AUTORUN_LEDS[55][2] = 4;
  AUTORUN_LEDS[56][0] = 0;  //19
  AUTORUN_LEDS[56][1] = 8;
  AUTORUN_LEDS[56][2] = 8;
  AUTORUN_LEDS[57][0] = 0;  //1
  AUTORUN_LEDS[57][1] = 8;
  AUTORUN_LEDS[57][2] = 16;
  AUTORUN_LEDS[58][0] = 0;  //2
  AUTORUN_LEDS[58][1] = 128;
  AUTORUN_LEDS[58][2] = 16;
  AUTORUN_LEDS[59][0] = 0;  //3
  AUTORUN_LEDS[59][1] = 128;
  AUTORUN_LEDS[59][2] = 32;
  AUTORUN_LEDS[60][0] = 0;  //4
  AUTORUN_LEDS[60][1] = 128;
  AUTORUN_LEDS[60][2] = 64;
  AUTORUN_LEDS[61][0] = 0;  //5
  AUTORUN_LEDS[61][1] = 128;
  AUTORUN_LEDS[61][2] = 128;
  AUTORUN_LEDS[62][0] = 0;  //6
  AUTORUN_LEDS[62][1] = 16;
  AUTORUN_LEDS[62][2] = 16;
  AUTORUN_LEDS[63][0] = 0;  //7
  AUTORUN_LEDS[63][1] = 64;
  AUTORUN_LEDS[63][2] = 16;

//Quarter C  
  AUTORUN_LEDS[64][0] = 0;  //8
  AUTORUN_LEDS[64][1] = 64;
  AUTORUN_LEDS[64][2] = 32;
  AUTORUN_LEDS[65][0] = 0;  //9
  AUTORUN_LEDS[65][1] = 64;
  AUTORUN_LEDS[65][2] = 64;
  AUTORUN_LEDS[66][0] = 0;  //10
  AUTORUN_LEDS[66][1] = 64;
  AUTORUN_LEDS[66][2] = 128;
  AUTORUN_LEDS[67][0] = 0;   //11
  AUTORUN_LEDS[67][1] = 32;
  AUTORUN_LEDS[67][2] = 16;
  AUTORUN_LEDS[68][0] = 0;  //12
  AUTORUN_LEDS[68][1] = 32;
  AUTORUN_LEDS[68][2] = 32;
  AUTORUN_LEDS[69][0] = 0;  //13
  AUTORUN_LEDS[69][1] = 32;
  AUTORUN_LEDS[69][2] = 64;
  AUTORUN_LEDS[70][0] = 0;  //14
  AUTORUN_LEDS[70][1] = 32;
  AUTORUN_LEDS[70][2] = 128;
  AUTORUN_LEDS[71][0] = 0;  //15
  AUTORUN_LEDS[71][1] = 16;
  AUTORUN_LEDS[71][2] = 32;
  AUTORUN_LEDS[72][0] = 0;  //16
  AUTORUN_LEDS[72][1] = 16;
  AUTORUN_LEDS[72][2] = 64;
  AUTORUN_LEDS[73][0] = 0;  //17
  AUTORUN_LEDS[73][1] = 16;
  AUTORUN_LEDS[73][2] = 128;
  AUTORUN_LEDS[74][0] = 0;  //17
  AUTORUN_LEDS[74][1] = 8;
  AUTORUN_LEDS[74][2] = 64;
  AUTORUN_LEDS[75][0] = 0;  //19
  AUTORUN_LEDS[75][1] = 8;
  
  AUTORUN_LEDS[75][2] = 128;
  AUTORUN_LEDS[76][0] = 0;  //19
  AUTORUN_LEDS[76][1] = 8;
  AUTORUN_LEDS[76][2] = 128;
  AUTORUN_LEDS[77][0] = 0;  //19
  AUTORUN_LEDS[77][1] = 8;
  AUTORUN_LEDS[77][2] = 128;
  AUTORUN_LEDS[78][0] = 0;  //19
  AUTORUN_LEDS[78][1] = 8;
  AUTORUN_LEDS[78][2] = 128;
  AUTORUN_LEDS[79][0] = 0;  //19
  AUTORUN_LEDS[79][1] = 8;
  AUTORUN_LEDS[79][2] = 128;
  AUTORUN_LEDS[80][0] = 0;  //19
  AUTORUN_LEDS[80][1] = 8;
  AUTORUN_LEDS[80][2] = 128;
  AUTORUN_LEDS[81][0] = 0;  //19
  AUTORUN_LEDS[81][1] = 8;
  AUTORUN_LEDS[81][2] = 128;
  AUTORUN_LEDS[82][0] = 0;  //19
  AUTORUN_LEDS[82][1] = 8;
  AUTORUN_LEDS[82][2] = 128;
  AUTORUN_LEDS[83][0] = 0;  //19
  AUTORUN_LEDS[83][1] = 8;
  AUTORUN_LEDS[83][2] = 128;
  AUTORUN_LEDS[84][0] = 0;  //19
  AUTORUN_LEDS[84][1] = 8;
  AUTORUN_LEDS[84][2] = 128;
  AUTORUN_LEDS[85][0] = 0;  //19
  AUTORUN_LEDS[85][1] = 8;
  AUTORUN_LEDS[85][2] = 128;
  AUTORUN_LEDS[86][0] = 0;  //19
  AUTORUN_LEDS[86][1] = 8;
  AUTORUN_LEDS[86][2] = 128;
  AUTORUN_LEDS[87][0] = 0;  //19
  AUTORUN_LEDS[87][1] = 8;
  AUTORUN_LEDS[87][2] = 128;
  AUTORUN_LEDS[88][0] = 0;  //19
  AUTORUN_LEDS[88][1] = 8;
  AUTORUN_LEDS[88][2] = 128;
  AUTORUN_LEDS[89][0] = 0;  //19
  AUTORUN_LEDS[89][1] = 8;
  AUTORUN_LEDS[89][2] = 128;
  AUTORUN_LEDS[90][0] = 0;  //19
  AUTORUN_LEDS[90][1] = 8;
  AUTORUN_LEDS[90][2] = 128;
  AUTORUN_LEDS[91][0] = 0;  //19
  AUTORUN_LEDS[91][1] = 8;
  AUTORUN_LEDS[91][2] = 128;
  AUTORUN_LEDS[92][0] = 0;  //19
  AUTORUN_LEDS[92][1] = 8;
  AUTORUN_LEDS[92][2] = 128;
  AUTORUN_LEDS[93][0] = 0;  //19
  AUTORUN_LEDS[93][1] = 8;
  AUTORUN_LEDS[93][2] = 128;
  AUTORUN_LEDS[94][0] = 0;  //19
  AUTORUN_LEDS[94][1] = 8;
  AUTORUN_LEDS[94][2] = 128;
  AUTORUN_LEDS[95][0] = 0;  //19
  AUTORUN_LEDS[95][1] = 8;
  AUTORUN_LEDS[95][2] = 128;

//Quarter D
  AUTORUN_LEDS[96][0] = 128;  //14
  AUTORUN_LEDS[96][1] = 32;
  AUTORUN_LEDS[96][2] = 0;
  AUTORUN_LEDS[97][0] = 32;  //15
  AUTORUN_LEDS[97][1] = 16;
  AUTORUN_LEDS[97][2] = 0;
  AUTORUN_LEDS[98][0] = 64;  //16
  AUTORUN_LEDS[98][1] = 16;
  AUTORUN_LEDS[98][2] = 0;
  AUTORUN_LEDS[99][0] = 128;  //17
  AUTORUN_LEDS[99][1] = 16;
  AUTORUN_LEDS[99][2] = 0;
  AUTORUN_LEDS[100][0] = 64;  //18
  AUTORUN_LEDS[100][1] = 8;
  AUTORUN_LEDS[100][2] = 0;
  AUTORUN_LEDS[101][0] = 128;  //19
  AUTORUN_LEDS[101][1] = 8;
  AUTORUN_LEDS[101][2] = 0;
  AUTORUN_LEDS[102][0] = 0;  //1
  AUTORUN_LEDS[102][1]= 8;
  AUTORUN_LEDS[102][2] = 1;
  AUTORUN_LEDS[103][0] = 0;  //2
  AUTORUN_LEDS[103][1] = 128;
  AUTORUN_LEDS[103][2] = 1;
  AUTORUN_LEDS[104][0] = 0;  //3
  AUTORUN_LEDS[104][1] = 128;
  AUTORUN_LEDS[104][2] = 2;
  AUTORUN_LEDS[105][0] = 0;  //4
  AUTORUN_LEDS[105][1] = 128;
  AUTORUN_LEDS[105][2] = 4;
  AUTORUN_LEDS[106][0] = 0;  //5
  AUTORUN_LEDS[106][1] = 128;
  AUTORUN_LEDS[106][2] = 8;
  AUTORUN_LEDS[107][0] = 0;  //6
  AUTORUN_LEDS[107][1] = 16;
  AUTORUN_LEDS[107][2] = 1;
  AUTORUN_LEDS[108][0] = 0;  //7
  AUTORUN_LEDS[108][1] = 64;
  AUTORUN_LEDS[108][2] = 1;
  AUTORUN_LEDS[109][0] = 0;  //8
  AUTORUN_LEDS[109][1] = 64;
  AUTORUN_LEDS[109][2] = 2;
  AUTORUN_LEDS[110][0] = 0;  //9
  AUTORUN_LEDS[110][1] = 64;
  AUTORUN_LEDS[110][2] = 4;
  AUTORUN_LEDS[111][0] = 0;  //10
  AUTORUN_LEDS[111][1] = 64;
  AUTORUN_LEDS[111][2] = 8;
  AUTORUN_LEDS[112][0] = 0;  //11
  AUTORUN_LEDS[112][1] = 32;
  AUTORUN_LEDS[112][2] = 1;
  AUTORUN_LEDS[113][0] = 0;  //12
  AUTORUN_LEDS[113][1] = 32;
  AUTORUN_LEDS[113][2] = 2;
  AUTORUN_LEDS[114][0] = 0;  //13
  AUTORUN_LEDS[114][1] = 32;
  AUTORUN_LEDS[114][2] = 4;
  AUTORUN_LEDS[115][0] = 0;  //14
  AUTORUN_LEDS[115][1] = 32;
  AUTORUN_LEDS[115][2] = 8;
  AUTORUN_LEDS[116][0] = 0;   //15
  AUTORUN_LEDS[116][1] = 16;
  AUTORUN_LEDS[116][2] = 2;
  AUTORUN_LEDS[117][0] = 0;  //16
  AUTORUN_LEDS[117][1] = 16;
  AUTORUN_LEDS[117][2] = 4;
  AUTORUN_LEDS[118][0] = 0;  //17
  AUTORUN_LEDS[118][1] = 16;
  AUTORUN_LEDS[118][2] = 8;
  AUTORUN_LEDS[119][0] = 0;  //18
  AUTORUN_LEDS[119][1] = 8;
  AUTORUN_LEDS[119][2] = 4;
  AUTORUN_LEDS[120][0] = 0;  //19
  AUTORUN_LEDS[120][1] = 8;
  AUTORUN_LEDS[120][2] = 8;
  AUTORUN_LEDS[121][0] = 0;  //1
  AUTORUN_LEDS[121][1] = 8;
  AUTORUN_LEDS[121][2] = 16;
  AUTORUN_LEDS[122][0] = 0;  //2
  AUTORUN_LEDS[122][1] = 128;
  AUTORUN_LEDS[122][2] = 16;
  AUTORUN_LEDS[123][0] = 0;  //3
  AUTORUN_LEDS[123][1] = 128;
  AUTORUN_LEDS[123][2] = 32;
  AUTORUN_LEDS[124][0] = 0;  //4
  AUTORUN_LEDS[124][1] = 128;
  AUTORUN_LEDS[124][2] = 64;
  AUTORUN_LEDS[125][0] = 0;  //5
  AUTORUN_LEDS[125][1] = 128;
  AUTORUN_LEDS[125][2] = 128;
  AUTORUN_LEDS[126][0] = 0;  //6
  AUTORUN_LEDS[126][1] = 16;
  AUTORUN_LEDS[126][2] = 16;
  AUTORUN_LEDS[127][0] = 0;  //7
  AUTORUN_LEDS[127][1] = 64;
  AUTORUN_LEDS[127][2] = 16;
}

