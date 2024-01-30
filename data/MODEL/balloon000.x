xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 165;
 0.00000;70.47228;0.00207;,
 1.55558;69.86412;-1.71668;,
 0.00000;69.86412;-2.42861;,
 0.00000;70.47228;0.00207;,
 2.19992;69.86412;0.00207;,
 0.00000;70.47228;0.00207;,
 1.55558;69.86412;1.72082;,
 0.00000;70.47228;0.00207;,
 -0.00000;69.86412;2.43274;,
 0.00000;70.47228;0.00207;,
 -1.55558;69.86412;1.72082;,
 0.00000;70.47228;0.00207;,
 -2.19992;69.86412;0.00207;,
 0.00000;70.47228;0.00207;,
 -1.55558;69.86412;-1.71668;,
 0.00000;70.47228;0.00207;,
 0.00000;69.86412;-2.42861;,
 2.87433;68.13217;-3.17377;,
 0.00000;68.13217;-4.48924;,
 4.06492;68.13217;0.00207;,
 2.87433;68.13217;3.17790;,
 -0.00000;68.13217;4.49338;,
 -2.87433;68.13217;3.17790;,
 -4.06492;68.13217;0.00207;,
 -2.87433;68.13217;-3.17377;,
 0.00000;68.13217;-4.48924;,
 3.75549;65.54016;-4.14736;,
 0.00000;65.54016;-5.41812;,
 5.31107;65.54016;0.00207;,
 3.75549;65.54016;4.15149;,
 0.04252;65.33909;5.54644;,
 -3.75549;65.54016;4.15149;,
 -5.31107;65.54016;0.00207;,
 -3.75549;65.54016;-4.14736;,
 0.00000;65.54016;-5.41812;,
 4.06415;62.47504;-4.48839;,
 0.13845;62.04354;-5.57852;,
 5.74866;62.48266;0.00207;,
 4.06492;62.48266;4.49338;,
 0.08078;62.14033;5.63584;,
 -4.06492;62.48266;4.49337;,
 -5.74866;62.48266;0.00207;,
 -4.06492;62.48266;-4.48924;,
 0.13845;62.04354;-5.57852;,
 3.75626;59.43278;-4.14821;,
 0.13845;59.06135;-5.10694;,
 5.31107;59.42516;0.00207;,
 3.75549;59.42516;4.15149;,
 0.08078;59.08283;5.15235;,
 -3.75549;59.42516;4.15149;,
 -5.31107;59.42516;0.00207;,
 -3.75549;59.42516;-4.14736;,
 0.13845;59.06135;-5.10694;,
 2.87433;56.83315;-3.17377;,
 0.00000;56.83315;-3.97611;,
 4.06492;56.83315;0.00207;,
 2.87433;56.83315;3.17790;,
 -0.00000;56.83315;4.34030;,
 -2.87433;56.83315;3.17790;,
 -4.06492;56.83315;0.00207;,
 -2.87433;56.83315;-3.17377;,
 0.00000;56.83315;-3.97611;,
 1.55558;55.10120;-1.71668;,
 0.00000;55.10120;-2.29490;,
 2.19992;55.10120;0.00207;,
 1.55558;55.10120;1.72082;,
 -0.00000;55.10120;2.43274;,
 -1.55558;55.10120;1.72082;,
 -2.19992;55.10120;0.00207;,
 -1.55558;55.10120;-1.71668;,
 0.00000;55.10120;-2.29490;,
 0.00000;54.64084;0.00207;,
 0.00000;54.64084;0.00207;,
 0.00000;54.64084;0.00207;,
 0.00000;54.64084;0.00207;,
 0.00000;54.64084;0.00207;,
 0.00000;54.64084;0.00207;,
 0.00000;54.64084;0.00207;,
 0.00000;54.64084;0.00207;,
 0.00000;54.31088;-0.34165;,
 0.00000;55.21888;0.00000;,
 0.21647;54.31088;-0.24158;,
 0.00000;55.21888;0.00000;,
 0.30614;54.31088;0.00000;,
 0.00000;55.21888;0.00000;,
 0.21647;54.31088;0.24158;,
 0.00000;55.21888;0.00000;,
 -0.00000;54.31088;0.34165;,
 0.00000;55.21888;0.00000;,
 -0.21648;54.31088;0.24158;,
 0.00000;55.21888;0.00000;,
 -0.30614;54.31088;-0.00000;,
 0.00000;55.21888;0.00000;,
 -0.21648;54.31088;-0.24158;,
 0.00000;55.21888;0.00000;,
 0.00000;54.31088;-0.34165;,
 0.00000;54.31088;0.00000;,
 0.00000;54.31088;-0.34165;,
 0.21647;54.31088;-0.24158;,
 0.21647;54.31088;0.24158;,
 -0.00000;54.31088;0.34165;,
 -0.21648;54.31088;0.24158;,
 -0.30614;54.31088;-0.00000;,
 -0.21648;54.31088;-0.24158;,
 0.00000;54.31088;-0.34165;,
 0.00000;55.21888;0.00000;,
 0.21647;54.31088;-0.24158;,
 0.00000;55.21888;0.00000;,
 0.30614;54.31088;0.00000;,
 0.00000;55.21888;0.00000;,
 0.21647;54.31088;0.24158;,
 0.00000;55.21888;0.00000;,
 -0.00000;54.31088;0.34165;,
 0.00000;55.21888;0.00000;,
 -0.21648;54.31088;0.24158;,
 0.00000;55.21888;0.00000;,
 -0.30614;54.31088;-0.00000;,
 0.00000;55.21888;0.00000;,
 -0.21648;54.31088;-0.24158;,
 0.00000;55.21888;0.00000;,
 0.00000;54.31088;-0.34165;,
 0.00000;54.31088;0.00000;,
 0.00000;54.31088;-0.34165;,
 0.21647;54.31088;-0.24158;,
 0.30614;54.31088;0.00000;,
 0.21647;54.31088;0.24158;,
 -0.00000;54.31088;0.34165;,
 -0.21648;54.31088;0.24158;,
 -0.30614;54.31088;-0.00000;,
 -0.21648;54.31088;-0.24158;,
 0.30614;54.31088;0.00000;,
 0.00000;54.33002;-0.26229;,
 0.17644;54.33002;-0.18546;,
 0.17644;34.33002;-0.18546;,
 0.00000;34.33002;-0.26229;,
 0.24952;54.33002;0.00000;,
 0.24952;34.33002;0.00000;,
 0.17644;54.33002;0.18546;,
 0.17644;34.33002;0.18546;,
 -0.00000;54.33002;0.26229;,
 -0.00000;34.33002;0.26229;,
 -0.17644;54.33002;0.18546;,
 -0.17644;34.33002;0.18546;,
 -0.24952;54.33002;-0.00000;,
 -0.24952;34.33002;-0.00000;,
 -0.17644;54.33002;-0.18546;,
 -0.17644;34.33002;-0.18546;,
 0.00000;54.33002;-0.26229;,
 0.00000;34.33002;-0.26229;,
 0.00000;54.33002;0.00000;,
 0.00000;54.33002;0.00000;,
 0.00000;54.33002;0.00000;,
 0.00000;54.33002;0.00000;,
 0.00000;54.33002;0.00000;,
 0.00000;54.33002;0.00000;,
 0.00000;54.33002;0.00000;,
 0.00000;54.33002;0.00000;,
 0.00000;34.33002;0.00000;,
 0.00000;34.33002;0.00000;,
 0.00000;34.33002;0.00000;,
 0.00000;34.33002;0.00000;,
 0.00000;34.33002;0.00000;,
 0.00000;34.33002;0.00000;,
 0.00000;34.33002;0.00000;,
 0.00000;34.33002;0.00000;;
 
 119;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 4;2,1,17,18;,
 4;1,4,19,17;,
 4;4,6,20,19;,
 4;6,8,21,20;,
 4;8,10,22,21;,
 4;10,12,23,22;,
 4;12,14,24,23;,
 4;14,16,25,24;,
 4;18,17,26,27;,
 4;17,19,28,26;,
 4;19,20,29,28;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;27,26,35,36;,
 4;26,28,37,35;,
 4;28,29,38,37;,
 4;29,30,39,38;,
 4;30,31,40,39;,
 4;31,32,41,40;,
 4;32,33,42,41;,
 4;33,34,43,42;,
 4;36,35,44,45;,
 4;35,37,46,44;,
 4;37,38,47,46;,
 4;38,39,48,47;,
 4;39,40,49,48;,
 4;40,41,50,49;,
 4;41,42,51,50;,
 4;42,43,52,51;,
 4;45,44,53,54;,
 4;44,46,55,53;,
 4;46,47,56,55;,
 4;47,48,57,56;,
 4;48,49,58,57;,
 4;49,50,59,58;,
 4;50,51,60,59;,
 4;51,52,61,60;,
 4;54,53,62,63;,
 4;53,55,64,62;,
 4;55,56,65,64;,
 4;56,57,66,65;,
 4;57,58,67,66;,
 4;58,59,68,67;,
 4;59,60,69,68;,
 4;60,61,70,69;,
 3;63,62,71;,
 3;62,64,72;,
 3;64,65,73;,
 3;65,66,74;,
 3;66,67,75;,
 3;67,68,76;,
 3;68,69,77;,
 3;69,70,78;,
 3;79,80,81;,
 3;81,82,83;,
 3;83,84,85;,
 3;85,86,87;,
 3;87,88,89;,
 3;89,90,91;,
 3;91,92,93;,
 3;93,94,95;,
 3;96,97,98;,
 3;96,99,100;,
 3;96,100,101;,
 3;96,101,102;,
 3;96,102,103;,
 3;96,103,97;,
 3;104,105,106;,
 3;106,107,108;,
 3;108,109,110;,
 3;110,111,112;,
 3;112,113,114;,
 3;114,115,116;,
 3;116,117,118;,
 3;118,119,120;,
 3;121,122,123;,
 3;121,123,124;,
 3;121,124,125;,
 3;121,125,126;,
 3;121,126,127;,
 3;121,127,128;,
 3;121,128,129;,
 3;121,129,122;,
 4;99,96,98,130;,
 4;131,132,133,134;,
 4;132,135,136,133;,
 4;135,137,138,136;,
 4;137,139,140,138;,
 4;139,141,142,140;,
 4;141,143,144,142;,
 4;143,145,146,144;,
 4;145,147,148,146;,
 3;149,132,131;,
 3;150,135,132;,
 3;151,137,135;,
 3;152,139,137;,
 3;153,141,139;,
 3;154,143,141;,
 3;155,145,143;,
 3;156,147,145;,
 3;157,134,133;,
 3;158,133,136;,
 3;159,136,138;,
 3;160,138,140;,
 3;161,140,142;,
 3;162,142,144;,
 3;163,144,146;,
 3;164,146,148;;
 
 MeshMaterialList {
  3;
  119;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  1;;
  Material {
   0.800000;0.009412;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.109804;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  79;
  -0.000000;1.000000;-0.000000;,
  -0.000000;0.892487;-0.451073;,
  0.345623;0.883513;-0.316148;,
  0.484531;0.874774;0.000000;,
  0.345623;0.883513;0.316148;,
  -0.000000;0.892487;0.451073;,
  -0.345623;0.883513;0.316148;,
  -0.484531;0.874774;0.000000;,
  -0.345623;0.883513;-0.316148;,
  -0.000000;0.596498;-0.802615;,
  0.577875;0.599944;-0.553288;,
  0.803652;0.595099;0.000000;,
  0.576967;0.604330;0.549449;,
  0.000634;0.605348;0.795960;,
  -0.576672;0.603672;0.550481;,
  -0.803652;0.595099;0.000000;,
  -0.577875;0.599944;-0.553289;,
  0.001855;0.244046;-0.969762;,
  0.669509;0.278594;-0.688580;,
  0.956546;0.291581;-0.000057;,
  0.673803;0.280998;0.683396;,
  0.002771;0.251397;0.967880;,
  -0.671909;0.279432;0.685898;,
  -0.956524;0.291655;0.000000;,
  -0.668570;0.276428;-0.690364;,
  0.006410;-0.027047;-0.999614;,
  0.681199;-0.013301;-0.731978;,
  1.000000;-0.000084;-0.000057;,
  0.685545;-0.016296;0.727848;,
  0.004854;-0.031392;0.999495;,
  -0.681949;-0.017248;0.731196;,
  -1.000000;0.000000;0.000000;,
  -0.676380;-0.015900;-0.736382;,
  0.006610;-0.298612;-0.954352;,
  0.647024;-0.313486;-0.695045;,
  0.956547;-0.291577;-0.000075;,
  0.659631;-0.294439;0.691514;,
  0.003716;-0.269265;0.963059;,
  -0.656871;-0.291530;0.695364;,
  -0.956524;-0.291655;0.000000;,
  -0.641933;-0.310655;-0.701010;,
  0.002017;-0.585186;-0.810896;,
  0.542349;-0.611719;-0.575897;,
  0.803695;-0.595042;-0.000074;,
  0.568912;-0.601071;0.561295;,
  0.000974;-0.586665;0.809830;,
  -0.568818;-0.598700;0.563919;,
  -0.803652;-0.595099;-0.000000;,
  -0.541315;-0.609307;-0.579416;,
  0.000000;-0.884560;-0.466427;,
  0.309235;-0.895077;-0.321265;,
  0.455900;-0.890031;0.000000;,
  0.323042;-0.896829;0.302229;,
  0.000000;-0.901359;0.433074;,
  -0.323042;-0.896829;0.302229;,
  -0.455900;-0.890031;-0.000000;,
  -0.309235;-0.895077;-0.321265;,
  0.000000;-0.999996;-0.002705;,
  0.000000;0.352160;-0.935940;,
  0.692564;0.335075;-0.638812;,
  0.947589;0.319491;0.000000;,
  0.692564;0.335075;0.638812;,
  -0.000000;0.352160;0.935940;,
  -0.692564;0.335075;0.638811;,
  -0.947589;0.319491;0.000000;,
  -0.692564;0.335075;-0.638811;,
  0.865748;0.366918;-0.340370;,
  0.000000;-1.000000;-0.000000;,
  -0.397070;0.323208;-0.858994;,
  0.000000;1.000000;0.000000;,
  -0.000000;0.000000;-1.000000;,
  0.719465;0.000000;-0.694528;,
  1.000000;0.000000;0.000000;,
  0.719465;0.000000;0.694528;,
  -0.000000;0.000000;1.000000;,
  -0.719466;0.000000;0.694528;,
  -1.000000;0.000000;0.000000;,
  -0.719466;0.000000;-0.694528;,
  0.000000;-1.000000;-0.000000;;
  119;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,1,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,17,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,24,32,31;,
  4;24,17,25,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,32,40,39;,
  4;32,25,33,40;,
  4;33,34,42,41;,
  4;34,35,43,42;,
  4;35,36,44,43;,
  4;36,37,45,44;,
  4;37,38,46,45;,
  4;38,39,47,46;,
  4;39,40,48,47;,
  4;40,33,41,48;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,47,55,54;,
  4;47,48,56,55;,
  4;48,41,49,56;,
  3;49,50,57;,
  3;50,51,57;,
  3;51,52,57;,
  3;52,53,57;,
  3;53,54,57;,
  3;54,55,57;,
  3;55,56,57;,
  3;56,49,57;,
  3;58,66,59;,
  3;59,66,60;,
  3;60,66,61;,
  3;61,62,62;,
  3;62,62,63;,
  3;63,64,64;,
  3;64,64,65;,
  3;65,68,58;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;58,66,59;,
  3;59,66,60;,
  3;60,66,61;,
  3;61,62,62;,
  3;62,62,63;,
  3;63,64,64;,
  3;64,64,65;,
  3;65,68,58;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  4;67,67,67,67;,
  4;70,71,71,70;,
  4;71,72,72,71;,
  4;72,73,73,72;,
  4;73,74,74,73;,
  4;74,75,75,74;,
  4;75,76,76,75;,
  4;76,77,77,76;,
  4;77,70,70,77;,
  3;69,69,69;,
  3;69,69,69;,
  3;69,69,69;,
  3;69,69,69;,
  3;69,69,69;,
  3;69,69,69;,
  3;69,69,69;,
  3;69,69,69;,
  3;78,78,78;,
  3;78,78,78;,
  3;78,78,78;,
  3;78,78,78;,
  3;78,78,78;,
  3;78,78,78;,
  3;78,78,78;,
  3;78,78,78;;
 }
 MeshTextureCoords {
  165;
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.000000;1.000000;,
  0.062500;0.000000;,
  0.125000;1.000000;,
  0.125000;0.000000;,
  0.250000;1.000000;,
  0.187500;0.000000;,
  0.375000;1.000000;,
  0.250000;0.000000;,
  0.500000;1.000000;,
  0.312500;0.000000;,
  0.625000;1.000000;,
  0.375000;0.000000;,
  0.750000;1.000000;,
  0.437500;0.000000;,
  0.875000;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.062500;0.000000;,
  0.125000;1.000000;,
  0.125000;0.000000;,
  0.250000;1.000000;,
  0.187500;0.000000;,
  0.375000;1.000000;,
  0.250000;0.000000;,
  0.500000;1.000000;,
  0.312500;0.000000;,
  0.625000;1.000000;,
  0.375000;0.000000;,
  0.750000;1.000000;,
  0.437500;0.000000;,
  0.875000;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.187500;0.000000;,
  0.312500;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.687500;0.000000;,
  0.812500;0.000000;,
  0.937500;0.000000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}