#include <cs50.h>
#include <stdio.h>

int get_initial_number(string text);
void get_pokemons(string pokemons[898]);

// 対象のポケモン数
const int POKEMONS_COUNT = 898;
// アルファベット数
const int ALPHABETS_COUNT = 26;

int main(void)
{
    // ポケモン名を格納する配列
    string pokemons[POKEMONS_COUNT];
    // ポケモンを配列に格納する
    get_pokemons(pokemons);

    // イニシャルごとに何匹いるか保存する配列
    // 1つめの要素がAから始めるポケモンの数、26番目の要素がZから始めるポケモンの数となる
    // すべて0で初期化する
    int initial_counts[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // ポケモンのイニシャルごとの匹数をカウントする
    for (int i = 0; i < POKEMONS_COUNT; i++)
    {
        initial_counts[get_initial_number(pokemons[i])]++;
    }

    // 結果出力(A-Zまでの26回繰り返す)
    for (int i = 0; i < ALPHABETS_COUNT; i++)
    {
        // TODO：アルファベット毎にその数を出力する。それぞれで改行すること。
        // 例    A: 40
        //       B: 48
        // initial_counts[0]には、Aから始めるポケモン匹数が入っている
        printf("%c: %3d\n", (char)(65 + i), initial_counts[i]);
    }

    return 0;
}

// Aであれば0
// Bであれば1
// ....
// Zであれば25が返る
// 条件：1文字目はアルファベット大文字しか入っていないものとする
//       そのためA-Z以外かどうかチェックする必要はない
int get_initial_number(string text)
{
    // TODO：引数のtextから頭文字を取得し、A-Zを0-25の数値で返す
    int initNum;
    for (int i = 0; i < ALPHABETS_COUNT; i++)
    {
        if (text[0] == 65 + i)
        {
            initNum = i;
        }
    }
    return initNum;
}


// ポケモンを配列に格納していく
// ポケモンおよびポケモン名の一部は任天堂株式会社の登録商標です。
void get_pokemons(string pokemons[POKEMONS_COUNT])
{
    pokemons[0] = "Bulbasaur";
    pokemons[1] = "Ivysaur";
    pokemons[2] = "Venusaur";
    pokemons[3] = "Charmander";
    pokemons[4] = "Charmeleon";
    pokemons[5] = "Charizard";
    pokemons[6] = "Squirtle";
    pokemons[7] = "Wartortle";
    pokemons[8] = "Blastoise";
    pokemons[9] = "Caterpie";
    pokemons[10] = "Metapod";
    pokemons[11] = "Butterfree";
    pokemons[12] = "Weedle";
    pokemons[13] = "Kakuna";
    pokemons[14] = "Beedrill";
    pokemons[15] = "Pidgey";
    pokemons[16] = "Pidgeotto";
    pokemons[17] = "Pidgeot";
    pokemons[18] = "Rattata";
    pokemons[19] = "Raticate";
    pokemons[20] = "Spearow";
    pokemons[21] = "Fearow";
    pokemons[22] = "Ekans";
    pokemons[23] = "Arbok";
    pokemons[24] = "Pikachu";
    pokemons[25] = "Raichu";
    pokemons[26] = "Sandshrew";
    pokemons[27] = "Sandslash";
    pokemons[28] = "Nidoran";
    pokemons[29] = "Nidorina";
    pokemons[30] = "Nidoqueen";
    pokemons[31] = "Nidoran";
    pokemons[32] = "Nidorino";
    pokemons[33] = "Nidoking";
    pokemons[34] = "Clefairy";
    pokemons[35] = "Clefable";
    pokemons[36] = "Vulpix";
    pokemons[37] = "Ninetales";
    pokemons[38] = "Jigglypuff";
    pokemons[39] = "Wigglytuff";
    pokemons[40] = "Zubat";
    pokemons[41] = "Golbat";
    pokemons[42] = "Oddish";
    pokemons[43] = "Gloom";
    pokemons[44] = "Vileplume";
    pokemons[45] = "Paras";
    pokemons[46] = "Parasect";
    pokemons[47] = "Venonat";
    pokemons[48] = "Venomoth";
    pokemons[49] = "Diglett";
    pokemons[50] = "Dugtrio";
    pokemons[51] = "Meowth";
    pokemons[52] = "Persian";
    pokemons[53] = "Psyduck";
    pokemons[54] = "Golduck";
    pokemons[55] = "Mankey";
    pokemons[56] = "Primeape";
    pokemons[57] = "Growlithe";
    pokemons[58] = "Arcanine";
    pokemons[59] = "Poliwag";
    pokemons[60] = "Poliwhirl";
    pokemons[61] = "Poliwrath";
    pokemons[62] = "Abra";
    pokemons[63] = "Kadabra";
    pokemons[64] = "Alakazam";
    pokemons[65] = "Machop";
    pokemons[66] = "Machoke";
    pokemons[67] = "Machamp";
    pokemons[68] = "Bellsprout";
    pokemons[69] = "Weepinbell";
    pokemons[70] = "Victreebel";
    pokemons[71] = "Tentacool";
    pokemons[72] = "Tentacruel";
    pokemons[73] = "Geodude";
    pokemons[74] = "Graveler";
    pokemons[75] = "Golem";
    pokemons[76] = "Ponyta";
    pokemons[77] = "Rapidash";
    pokemons[78] = "Slowpoke";
    pokemons[79] = "Slowbro";
    pokemons[80] = "Magnemite";
    pokemons[81] = "Magneton";
    pokemons[82] = "Farfetch'd";
    pokemons[83] = "Doduo";
    pokemons[84] = "Dodrio";
    pokemons[85] = "Seel";
    pokemons[86] = "Dewgong";
    pokemons[87] = "Grimer";
    pokemons[88] = "Muk";
    pokemons[89] = "Shellder";
    pokemons[90] = "Cloyster";
    pokemons[91] = "Gastly";
    pokemons[92] = "Haunter";
    pokemons[93] = "Gengar";
    pokemons[94] = "Onix";
    pokemons[95] = "Drowzee";
    pokemons[96] = "Hypno";
    pokemons[97] = "Krabby";
    pokemons[98] = "Kingler";
    pokemons[99] = "Voltorb";
    pokemons[100] = "Electrode";
    pokemons[101] = "Exeggcute";
    pokemons[102] = "Exeggutor";
    pokemons[103] = "Cubone";
    pokemons[104] = "Marowak";
    pokemons[105] = "Hitmonlee";
    pokemons[106] = "Hitmonchan";
    pokemons[107] = "Lickitung";
    pokemons[108] = "Koffing";
    pokemons[109] = "Weezing";
    pokemons[110] = "Rhyhorn";
    pokemons[111] = "Rhydon";
    pokemons[112] = "Chansey";
    pokemons[113] = "Tangela";
    pokemons[114] = "Kangaskhan";
    pokemons[115] = "Horsea";
    pokemons[116] = "Seadra";
    pokemons[117] = "Goldeen";
    pokemons[118] = "Seaking";
    pokemons[119] = "Staryu";
    pokemons[120] = "Starmie";
    pokemons[121] = "Mr.Mime";
    pokemons[122] = "Scyther";
    pokemons[123] = "Jynx";
    pokemons[124] = "Electabuzz";
    pokemons[125] = "Magmar";
    pokemons[126] = "Pinsir";
    pokemons[127] = "Tauros";
    pokemons[128] = "Magikarp";
    pokemons[129] = "Gyarados";
    pokemons[130] = "Lapras";
    pokemons[131] = "Ditto";
    pokemons[132] = "Eevee";
    pokemons[133] = "Vaporeon";
    pokemons[134] = "Jolteon";
    pokemons[135] = "Flareon";
    pokemons[136] = "Porygon";
    pokemons[137] = "Omanyte";
    pokemons[138] = "Omastar";
    pokemons[139] = "Kabuto";
    pokemons[140] = "Kabutops";
    pokemons[141] = "Aerodactyl";
    pokemons[142] = "Snorlax";
    pokemons[143] = "Articuno";
    pokemons[144] = "Zapdos";
    pokemons[145] = "Moltres";
    pokemons[146] = "Dratini";
    pokemons[147] = "Dragonair";
    pokemons[148] = "Dragonite";
    pokemons[149] = "Mewtwo";
    pokemons[150] = "Mew";
    pokemons[151] = "Chikorita";
    pokemons[152] = "Bayleef";
    pokemons[153] = "Meganium";
    pokemons[154] = "Cyndaquil";
    pokemons[155] = "Quilava";
    pokemons[156] = "Typhlosion";
    pokemons[157] = "Totodile";
    pokemons[158] = "Croconaw";
    pokemons[159] = "Feraligatr";
    pokemons[160] = "Sentret";
    pokemons[161] = "Furret";
    pokemons[162] = "Hoothoot";
    pokemons[163] = "Noctowl";
    pokemons[164] = "Ledyba";
    pokemons[165] = "Ledian";
    pokemons[166] = "Spinarak";
    pokemons[167] = "Ariados";
    pokemons[168] = "Crobat";
    pokemons[169] = "Chinchou";
    pokemons[170] = "Lanturn";
    pokemons[171] = "Pichu";
    pokemons[172] = "Cleffa";
    pokemons[173] = "Igglybuff";
    pokemons[174] = "Togepi";
    pokemons[175] = "Togetic";
    pokemons[176] = "Natu";
    pokemons[177] = "Xatu";
    pokemons[178] = "Mareep";
    pokemons[179] = "Flaaffy";
    pokemons[180] = "Ampharos";
    pokemons[181] = "Bellossom";
    pokemons[182] = "Marill";
    pokemons[183] = "Azumarill";
    pokemons[184] = "Sudowoodo";
    pokemons[185] = "Politoed";
    pokemons[186] = "Hoppip";
    pokemons[187] = "Skiploom";
    pokemons[188] = "Jumpluff";
    pokemons[189] = "Aipom";
    pokemons[190] = "Sunkern";
    pokemons[191] = "Sunflora";
    pokemons[192] = "Yanma";
    pokemons[193] = "Wooper";
    pokemons[194] = "Quagsire";
    pokemons[195] = "Espeon";
    pokemons[196] = "Umbreon";
    pokemons[197] = "Murkrow";
    pokemons[198] = "Slowking";
    pokemons[199] = "Misdreavus";
    pokemons[200] = "Unown";
    pokemons[201] = "Wobbuffet";
    pokemons[202] = "Girafarig";
    pokemons[203] = "Pineco";
    pokemons[204] = "Forretress";
    pokemons[205] = "Dunsparce";
    pokemons[206] = "Gligar";
    pokemons[207] = "Steelix";
    pokemons[208] = "Snubbull";
    pokemons[209] = "Granbull";
    pokemons[210] = "Qwilfish";
    pokemons[211] = "Scizor";
    pokemons[212] = "Shuckle";
    pokemons[213] = "Heracross";
    pokemons[214] = "Sneasel";
    pokemons[215] = "Teddiursa";
    pokemons[216] = "Ursaring";
    pokemons[217] = "Slugma";
    pokemons[218] = "Magcargo";
    pokemons[219] = "Swinub";
    pokemons[220] = "Piloswine";
    pokemons[221] = "Corsola";
    pokemons[222] = "Remoraid";
    pokemons[223] = "Octillery";
    pokemons[224] = "Delibird";
    pokemons[225] = "Mantine";
    pokemons[226] = "Skarmory";
    pokemons[227] = "Houndour";
    pokemons[228] = "Houndoom";
    pokemons[229] = "Kingdra";
    pokemons[230] = "Phanpy";
    pokemons[231] = "Donphan";
    pokemons[232] = "Porygon2";
    pokemons[233] = "Stantler";
    pokemons[234] = "Smeargle";
    pokemons[235] = "Tyrogue";
    pokemons[236] = "Hitmontop";
    pokemons[237] = "Smoochum";
    pokemons[238] = "Elekid";
    pokemons[239] = "Magby";
    pokemons[240] = "Miltank";
    pokemons[241] = "Blissey";
    pokemons[242] = "Raikou";
    pokemons[243] = "Entei";
    pokemons[244] = "Suicune";
    pokemons[245] = "Larvitar";
    pokemons[246] = "Pupitar";
    pokemons[247] = "Tyranitar";
    pokemons[248] = "Lugia";
    pokemons[249] = "Ho-Oh";
    pokemons[250] = "Celebi";
    pokemons[251] = "Treecko";
    pokemons[252] = "Grovyle";
    pokemons[253] = "Sceptile";
    pokemons[254] = "Torchic";
    pokemons[255] = "Combusken";
    pokemons[256] = "Blaziken";
    pokemons[257] = "Mudkip";
    pokemons[258] = "Marshtomp";
    pokemons[259] = "Swampert";
    pokemons[260] = "Poochyena";
    pokemons[261] = "Mightyena";
    pokemons[262] = "Zigzagoon";
    pokemons[263] = "Linoone";
    pokemons[264] = "Wurmple";
    pokemons[265] = "Silcoon";
    pokemons[266] = "Beautifly";
    pokemons[267] = "Cascoon";
    pokemons[268] = "Dustox";
    pokemons[269] = "Lotad";
    pokemons[270] = "Lombre";
    pokemons[271] = "Ludicolo";
    pokemons[272] = "Seedot";
    pokemons[273] = "Nuzleaf";
    pokemons[274] = "Shiftry";
    pokemons[275] = "Taillow";
    pokemons[276] = "Swellow";
    pokemons[277] = "Wingull";
    pokemons[278] = "Pelipper";
    pokemons[279] = "Ralts";
    pokemons[280] = "Kirlia";
    pokemons[281] = "Gardevoir";
    pokemons[282] = "Surskit";
    pokemons[283] = "Masquerain";
    pokemons[284] = "Shroomish";
    pokemons[285] = "Breloom";
    pokemons[286] = "Slakoth";
    pokemons[287] = "Vigoroth";
    pokemons[288] = "Slaking";
    pokemons[289] = "Nincada";
    pokemons[290] = "Ninjask";
    pokemons[291] = "Shedinja";
    pokemons[292] = "Whismur";
    pokemons[293] = "Loudred";
    pokemons[294] = "Exploud";
    pokemons[295] = "Makuhita";
    pokemons[296] = "Hariyama";
    pokemons[297] = "Azurill";
    pokemons[298] = "Nosepass";
    pokemons[299] = "Skitty";
    pokemons[300] = "Delcatty";
    pokemons[301] = "Sableye";
    pokemons[302] = "Mawile";
    pokemons[303] = "Aron";
    pokemons[304] = "Lairon";
    pokemons[305] = "Aggron";
    pokemons[306] = "Meditite";
    pokemons[307] = "Medicham";
    pokemons[308] = "Electrike";
    pokemons[309] = "Manectric";
    pokemons[310] = "Plusle";
    pokemons[311] = "Minun";
    pokemons[312] = "Volbeat";
    pokemons[313] = "Illumise";
    pokemons[314] = "Roselia";
    pokemons[315] = "Gulpin";
    pokemons[316] = "Swalot";
    pokemons[317] = "Carvanha";
    pokemons[318] = "Sharpedo";
    pokemons[319] = "Wailmer";
    pokemons[320] = "Wailord";
    pokemons[321] = "Numel";
    pokemons[322] = "Camerupt";
    pokemons[323] = "Torkoal";
    pokemons[324] = "Spoink";
    pokemons[325] = "Grumpig";
    pokemons[326] = "Spinda";
    pokemons[327] = "Trapinch";
    pokemons[328] = "Vibrava";
    pokemons[329] = "Flygon";
    pokemons[330] = "Cacnea";
    pokemons[331] = "Cacturne";
    pokemons[332] = "Swablu";
    pokemons[333] = "Altaria";
    pokemons[334] = "Zangoose";
    pokemons[335] = "Seviper";
    pokemons[336] = "Lunatone";
    pokemons[337] = "Solrock";
    pokemons[338] = "Barboach";
    pokemons[339] = "Whiscash";
    pokemons[340] = "Corphish";
    pokemons[341] = "Crawdaunt";
    pokemons[342] = "Baltoy";
    pokemons[343] = "Claydol";
    pokemons[344] = "Lileep";
    pokemons[345] = "Cradily";
    pokemons[346] = "Anorith";
    pokemons[347] = "Armaldo";
    pokemons[348] = "Feebas";
    pokemons[349] = "Milotic";
    pokemons[350] = "Castform";
    pokemons[351] = "Kecleon";
    pokemons[352] = "Shuppet";
    pokemons[353] = "Banette";
    pokemons[354] = "Duskull";
    pokemons[355] = "Dusclops";
    pokemons[356] = "Tropius";
    pokemons[357] = "Chimecho";
    pokemons[358] = "Absol";
    pokemons[359] = "Wynaut";
    pokemons[360] = "Snorunt";
    pokemons[361] = "Glalie";
    pokemons[362] = "Spheal";
    pokemons[363] = "Sealeo";
    pokemons[364] = "Walrein";
    pokemons[365] = "Clamperl";
    pokemons[366] = "Huntail";
    pokemons[367] = "Gorebyss";
    pokemons[368] = "Relicanth";
    pokemons[369] = "Luvdisc";
    pokemons[370] = "Bagon";
    pokemons[371] = "Shelgon";
    pokemons[372] = "Salamence";
    pokemons[373] = "Beldum";
    pokemons[374] = "Metang";
    pokemons[375] = "Metagross";
    pokemons[376] = "Regirock";
    pokemons[377] = "Regice";
    pokemons[378] = "Registeel";
    pokemons[379] = "Latias";
    pokemons[380] = "Latios";
    pokemons[381] = "Kyogre";
    pokemons[382] = "Groudon";
    pokemons[383] = "Rayquaza";
    pokemons[384] = "Jirachi";
    pokemons[385] = "Deoxys";
    pokemons[386] = "Turtwig";
    pokemons[387] = "Grotle";
    pokemons[388] = "Torterra";
    pokemons[389] = "Chimchar";
    pokemons[390] = "Monferno";
    pokemons[391] = "Infernape";
    pokemons[392] = "Piplup";
    pokemons[393] = "Prinplup";
    pokemons[394] = "Empoleon";
    pokemons[395] = "Starly";
    pokemons[396] = "Staravia";
    pokemons[397] = "Staraptor";
    pokemons[398] = "Bidoof";
    pokemons[399] = "Bibarel";
    pokemons[400] = "Kricketot";
    pokemons[401] = "Kricketune";
    pokemons[402] = "Shinx";
    pokemons[403] = "Luxio";
    pokemons[404] = "Luxray";
    pokemons[405] = "Budew";
    pokemons[406] = "Roserade";
    pokemons[407] = "Cranidos";
    pokemons[408] = "Rampardos";
    pokemons[409] = "Shieldon";
    pokemons[410] = "Bastiodon";
    pokemons[411] = "Burmy";
    pokemons[412] = "Wormadam";
    pokemons[413] = "Mothim";
    pokemons[414] = "Combee";
    pokemons[415] = "Vespiquen";
    pokemons[416] = "Pachirisu";
    pokemons[417] = "Buizel";
    pokemons[418] = "Floatzel";
    pokemons[419] = "Cherubi";
    pokemons[420] = "Cherrim";
    pokemons[421] = "Shellos";
    pokemons[422] = "Gastrodon";
    pokemons[423] = "Ambipom";
    pokemons[424] = "Drifloon";
    pokemons[425] = "Drifblim";
    pokemons[426] = "Buneary";
    pokemons[427] = "Lopunny";
    pokemons[428] = "Mismagius";
    pokemons[429] = "Honchkrow";
    pokemons[430] = "Glameow";
    pokemons[431] = "Purugly";
    pokemons[432] = "Chingling";
    pokemons[433] = "Stunky";
    pokemons[434] = "Skuntank";
    pokemons[435] = "Bronzor";
    pokemons[436] = "Bronzong";
    pokemons[437] = "Bonsly";
    pokemons[438] = "MimeJr.";
    pokemons[439] = "Happiny";
    pokemons[440] = "Chatot";
    pokemons[441] = "Spiritomb";
    pokemons[442] = "Gible";
    pokemons[443] = "Gabite";
    pokemons[444] = "Garchomp";
    pokemons[445] = "Munchlax";
    pokemons[446] = "Riolu";
    pokemons[447] = "Lucario";
    pokemons[448] = "Hippopotas";
    pokemons[449] = "Hippowdon";
    pokemons[450] = "Skorupi";
    pokemons[451] = "Drapion";
    pokemons[452] = "Croagunk";
    pokemons[453] = "Toxicroak";
    pokemons[454] = "Carnivine";
    pokemons[455] = "Finneon";
    pokemons[456] = "Lumineon";
    pokemons[457] = "Mantyke";
    pokemons[458] = "Snover";
    pokemons[459] = "Abomasnow";
    pokemons[460] = "Weavile";
    pokemons[461] = "Magnezone";
    pokemons[462] = "Lickilicky";
    pokemons[463] = "Rhyperior";
    pokemons[464] = "Tangrowth";
    pokemons[465] = "Electivire";
    pokemons[466] = "Magmortar";
    pokemons[467] = "Togekiss";
    pokemons[468] = "Yanmega";
    pokemons[469] = "Leafeon";
    pokemons[470] = "Glaceon";
    pokemons[471] = "Gliscor";
    pokemons[472] = "Mamoswine";
    pokemons[473] = "Porygon-Z";
    pokemons[474] = "Gallade";
    pokemons[475] = "Probopass";
    pokemons[476] = "Dusknoir";
    pokemons[477] = "Froslass";
    pokemons[478] = "Rotom";
    pokemons[479] = "Uxie";
    pokemons[480] = "Mesprit";
    pokemons[481] = "Azelf";
    pokemons[482] = "Dialga";
    pokemons[483] = "Palkia";
    pokemons[484] = "Heatran";
    pokemons[485] = "Regigigas";
    pokemons[486] = "Giratina";
    pokemons[487] = "Cresselia";
    pokemons[488] = "Phione";
    pokemons[489] = "Manaphy";
    pokemons[490] = "Darkrai";
    pokemons[491] = "Shaymin";
    pokemons[492] = "Arceus";
    pokemons[493] = "Victini";
    pokemons[494] = "Snivy";
    pokemons[495] = "Servine";
    pokemons[496] = "Serperior";
    pokemons[497] = "Tepig";
    pokemons[498] = "Pignite";
    pokemons[499] = "Emboar";
    pokemons[500] = "Oshawott";
    pokemons[501] = "Dewott";
    pokemons[502] = "Samurott";
    pokemons[503] = "Patrat";
    pokemons[504] = "Watchog";
    pokemons[505] = "Lillipup";
    pokemons[506] = "Herdier";
    pokemons[507] = "Stoutland";
    pokemons[508] = "Purrloin";
    pokemons[509] = "Liepard";
    pokemons[510] = "Pansage";
    pokemons[511] = "Simisage";
    pokemons[512] = "Pansear";
    pokemons[513] = "Simisear";
    pokemons[514] = "Panpour";
    pokemons[515] = "Simipour";
    pokemons[516] = "Munna";
    pokemons[517] = "Musharna";
    pokemons[518] = "Pidove";
    pokemons[519] = "Tranquill";
    pokemons[520] = "Unfezant";
    pokemons[521] = "Blitzle";
    pokemons[522] = "Zebstrika";
    pokemons[523] = "Roggenrola";
    pokemons[524] = "Boldore";
    pokemons[525] = "Gigalith";
    pokemons[526] = "Woobat";
    pokemons[527] = "Swoobat";
    pokemons[528] = "Drilbur";
    pokemons[529] = "Excadrill";
    pokemons[530] = "Audino";
    pokemons[531] = "Timburr";
    pokemons[532] = "Gurdurr";
    pokemons[533] = "Conkeldurr";
    pokemons[534] = "Tympole";
    pokemons[535] = "Palpitoad";
    pokemons[536] = "Seismitoad";
    pokemons[537] = "Throh";
    pokemons[538] = "Sawk";
    pokemons[539] = "Sewaddle";
    pokemons[540] = "Swadloon";
    pokemons[541] = "Leavanny";
    pokemons[542] = "Venipede";
    pokemons[543] = "Whirlipede";
    pokemons[544] = "Scolipede";
    pokemons[545] = "Cottonee";
    pokemons[546] = "Whimsicott";
    pokemons[547] = "Petilil";
    pokemons[548] = "Lilligant";
    pokemons[549] = "Basculin";
    pokemons[550] = "Sandile";
    pokemons[551] = "Krokorok";
    pokemons[552] = "Krookodile";
    pokemons[553] = "Darumaka";
    pokemons[554] = "Darmanitan";
    pokemons[555] = "Maractus";
    pokemons[556] = "Dwebble";
    pokemons[557] = "Crustle";
    pokemons[558] = "Scraggy";
    pokemons[559] = "Scrafty";
    pokemons[560] = "Sigilyph";
    pokemons[561] = "Yamask";
    pokemons[562] = "Cofagrigus";
    pokemons[563] = "Tirtouga";
    pokemons[564] = "Carracosta";
    pokemons[565] = "Archen";
    pokemons[566] = "Archeops";
    pokemons[567] = "Trubbish";
    pokemons[568] = "Garbodor";
    pokemons[569] = "Zorua";
    pokemons[570] = "Zoroark";
    pokemons[571] = "Minccino";
    pokemons[572] = "Cinccino";
    pokemons[573] = "Gothita";
    pokemons[574] = "Gothorita";
    pokemons[575] = "Gothitelle";
    pokemons[576] = "Solosis";
    pokemons[577] = "Duosion";
    pokemons[578] = "Reuniclus";
    pokemons[579] = "Ducklett";
    pokemons[580] = "Swanna";
    pokemons[581] = "Vanillite";
    pokemons[582] = "Vanillish";
    pokemons[583] = "Vanilluxe";
    pokemons[584] = "Deerling";
    pokemons[585] = "Sawsbuck";
    pokemons[586] = "Emolga";
    pokemons[587] = "Karrablast";
    pokemons[588] = "Escavalier";
    pokemons[589] = "Foongus";
    pokemons[590] = "Amoonguss";
    pokemons[591] = "Frillish";
    pokemons[592] = "Jellicent";
    pokemons[593] = "Alomomola";
    pokemons[594] = "Joltik";
    pokemons[595] = "Galvantula";
    pokemons[596] = "Ferroseed";
    pokemons[597] = "Ferrothorn";
    pokemons[598] = "Klink";
    pokemons[599] = "Klang";
    pokemons[600] = "Klinklang";
    pokemons[601] = "Tynamo";
    pokemons[602] = "Eelektrik";
    pokemons[603] = "Eelektross";
    pokemons[604] = "Elgyem";
    pokemons[605] = "Beheeyem";
    pokemons[606] = "Litwick";
    pokemons[607] = "Lampent";
    pokemons[608] = "Chandelure";
    pokemons[609] = "Axew";
    pokemons[610] = "Fraxure";
    pokemons[611] = "Haxorus";
    pokemons[612] = "Cubchoo";
    pokemons[613] = "Beartic";
    pokemons[614] = "Cryogonal";
    pokemons[615] = "Shelmet";
    pokemons[616] = "Accelgor";
    pokemons[617] = "Stunfisk";
    pokemons[618] = "Mienfoo";
    pokemons[619] = "Mienshao";
    pokemons[620] = "Druddigon";
    pokemons[621] = "Golett";
    pokemons[622] = "Golurk";
    pokemons[623] = "Pawniard";
    pokemons[624] = "Bisharp";
    pokemons[625] = "Bouffalant";
    pokemons[626] = "Rufflet";
    pokemons[627] = "Braviary";
    pokemons[628] = "Vullaby";
    pokemons[629] = "Mandibuzz";
    pokemons[630] = "Heatmor";
    pokemons[631] = "Durant";
    pokemons[632] = "Deino";
    pokemons[633] = "Zweilous";
    pokemons[634] = "Hydreigon";
    pokemons[635] = "Larvesta";
    pokemons[636] = "Volcarona";
    pokemons[637] = "Cobalion";
    pokemons[638] = "Terrakion";
    pokemons[639] = "Virizion";
    pokemons[640] = "Tornadus";
    pokemons[641] = "Thundurus";
    pokemons[642] = "Reshiram";
    pokemons[643] = "Zekrom";
    pokemons[644] = "Landorus";
    pokemons[645] = "Kyurem";
    pokemons[646] = "Keldeo";
    pokemons[647] = "Meloetta";
    pokemons[648] = "Genesect";
    pokemons[649] = "Chespin";
    pokemons[650] = "Quilladin";
    pokemons[651] = "Chesnaught";
    pokemons[652] = "Fennekin";
    pokemons[653] = "Braixen";
    pokemons[654] = "Delphox";
    pokemons[655] = "Froakie";
    pokemons[656] = "Frogadier";
    pokemons[657] = "Greninja";
    pokemons[658] = "Bunnelby";
    pokemons[659] = "Diggersby";
    pokemons[660] = "Fletchling";
    pokemons[661] = "Fletchinder";
    pokemons[662] = "Talonflame";
    pokemons[663] = "Scatterbug";
    pokemons[664] = "Spewpa";
    pokemons[665] = "Vivillon";
    pokemons[666] = "Litleo";
    pokemons[667] = "Pyroar";
    pokemons[668] = "Flabebe";
    pokemons[669] = "Floette";
    pokemons[670] = "Florges";
    pokemons[671] = "Skiddo";
    pokemons[672] = "Gogoat";
    pokemons[673] = "Pancham";
    pokemons[674] = "Pangoro";
    pokemons[675] = "Furfrou";
    pokemons[676] = "Espurr";
    pokemons[677] = "Meowstic";
    pokemons[678] = "Honedge";
    pokemons[679] = "Doublade";
    pokemons[680] = "Aegislash";
    pokemons[681] = "Spritzee";
    pokemons[682] = "Aromatisse";
    pokemons[683] = "Swirlix";
    pokemons[684] = "Slurpuff";
    pokemons[685] = "Inkay";
    pokemons[686] = "Malamar";
    pokemons[687] = "Binacle";
    pokemons[688] = "Barbaracle";
    pokemons[689] = "Skrelp";
    pokemons[690] = "Dragalge";
    pokemons[691] = "Clauncher";
    pokemons[692] = "Clawitzer";
    pokemons[693] = "Helioptile";
    pokemons[694] = "Heliolisk";
    pokemons[695] = "Tyrunt";
    pokemons[696] = "Tyrantrum";
    pokemons[697] = "Amaura";
    pokemons[698] = "Aurorus";
    pokemons[699] = "Sylveon";
    pokemons[700] = "Hawlucha";
    pokemons[701] = "Dedenne";
    pokemons[702] = "Carbink";
    pokemons[703] = "Goomy";
    pokemons[704] = "Sliggoo";
    pokemons[705] = "Goodra";
    pokemons[706] = "Klefki";
    pokemons[707] = "Phantump";
    pokemons[708] = "Trevenant";
    pokemons[709] = "Pumpkaboo";
    pokemons[710] = "Gourgeist";
    pokemons[711] = "Bergmite";
    pokemons[712] = "Avalugg";
    pokemons[713] = "Noibat";
    pokemons[714] = "Noivern";
    pokemons[715] = "Xerneas";
    pokemons[716] = "Yveltal";
    pokemons[717] = "Zygarde";
    pokemons[718] = "Diancie";
    pokemons[719] = "Hoopa";
    pokemons[720] = "Volcanion";
    pokemons[721] = "Rowlet";
    pokemons[722] = "Dartrix";
    pokemons[723] = "Decidueye";
    pokemons[724] = "Litten";
    pokemons[725] = "Torracat";
    pokemons[726] = "Incineroar";
    pokemons[727] = "Popplio";
    pokemons[728] = "Brionne";
    pokemons[729] = "Primarina";
    pokemons[730] = "Pikipek";
    pokemons[731] = "Trumbeak";
    pokemons[732] = "Toucannon";
    pokemons[733] = "Yungoos";
    pokemons[734] = "Gumshoos";
    pokemons[735] = "Grubbin";
    pokemons[736] = "Charjabug";
    pokemons[737] = "Vikavolt";
    pokemons[738] = "Crabrawler";
    pokemons[739] = "Crabominable";
    pokemons[740] = "Oricorio";
    pokemons[741] = "Cutiefly";
    pokemons[742] = "Ribombee";
    pokemons[743] = "Rockruff";
    pokemons[744] = "Lycanroc";
    pokemons[745] = "Wishiwashi";
    pokemons[746] = "Mareanie";
    pokemons[747] = "Toxapex";
    pokemons[748] = "Mudbray";
    pokemons[749] = "Mudsdale";
    pokemons[750] = "Dewpider";
    pokemons[751] = "Araquanid";
    pokemons[752] = "Fomantis";
    pokemons[753] = "Lurantis";
    pokemons[754] = "Morelull";
    pokemons[755] = "Shiinotic";
    pokemons[756] = "Salandit";
    pokemons[757] = "Salazzle";
    pokemons[758] = "Stufful";
    pokemons[759] = "Bewear";
    pokemons[760] = "Bounsweet";
    pokemons[761] = "Steenee";
    pokemons[762] = "Tsareena";
    pokemons[763] = "Comfey";
    pokemons[764] = "Oranguru";
    pokemons[765] = "Passimian";
    pokemons[766] = "Wimpod";
    pokemons[767] = "Golisopod";
    pokemons[768] = "Sandygast";
    pokemons[769] = "Palossand";
    pokemons[770] = "Pyukumuku";
    pokemons[771] = "TypeNull";
    pokemons[772] = "Silvally";
    pokemons[773] = "Minior";
    pokemons[774] = "Komala";
    pokemons[775] = "Turtonator";
    pokemons[776] = "Togedemaru";
    pokemons[777] = "Mimikyu";
    pokemons[778] = "Bruxish";
    pokemons[779] = "Drampa";
    pokemons[780] = "Dhelmise";
    pokemons[781] = "Jangmo-o";
    pokemons[782] = "Hakamo-o";
    pokemons[783] = "Kommo-o";
    pokemons[784] = "TapuKoko";
    pokemons[785] = "TapuLele";
    pokemons[786] = "TapuBulu";
    pokemons[787] = "TapuFini";
    pokemons[788] = "Cosmog";
    pokemons[789] = "Cosmoem";
    pokemons[790] = "Solgaleo";
    pokemons[791] = "Lunala";
    pokemons[792] = "Nihilego";
    pokemons[793] = "Buzzwole";
    pokemons[794] = "Pheromosa";
    pokemons[795] = "Xurkitree";
    pokemons[796] = "Celesteela";
    pokemons[797] = "Kartana";
    pokemons[798] = "Guzzlord";
    pokemons[799] = "Necrozma";
    pokemons[800] = "Magearna";
    pokemons[801] = "Marshadow";
    pokemons[802] = "Poipole";
    pokemons[803] = "Naganadel";
    pokemons[804] = "Stakataka";
    pokemons[805] = "Blacephalon";
    pokemons[806] = "Zeraora";
    pokemons[807] = "Meltan";
    pokemons[808] = "Melmetal";
    pokemons[809] = "Grookey";
    pokemons[810] = "Thwackey";
    pokemons[811] = "Rillaboom";
    pokemons[812] = "Scorbunny";
    pokemons[813] = "Raboot";
    pokemons[814] = "Cinderace";
    pokemons[815] = "Sobble";
    pokemons[816] = "Drizzile";
    pokemons[817] = "Inteleon";
    pokemons[818] = "Skwovet";
    pokemons[819] = "Greedent";
    pokemons[820] = "Rookidee";
    pokemons[821] = "Corvisquire";
    pokemons[822] = "Corviknight";
    pokemons[823] = "Blipbug";
    pokemons[824] = "Dottler";
    pokemons[825] = "Orbeetle";
    pokemons[826] = "Nickit";
    pokemons[827] = "Thievul";
    pokemons[828] = "Gossifleur";
    pokemons[829] = "Eldegoss";
    pokemons[830] = "Wooloo";
    pokemons[831] = "Dubwool";
    pokemons[832] = "Chewtle";
    pokemons[833] = "Drednaw";
    pokemons[834] = "Yamper";
    pokemons[835] = "Boltund";
    pokemons[836] = "Rolycoly";
    pokemons[837] = "Carkol";
    pokemons[838] = "Coalossal";
    pokemons[839] = "Applin";
    pokemons[840] = "Flapple";
    pokemons[841] = "Appletun";
    pokemons[842] = "Silicobra";
    pokemons[843] = "Sandaconda";
    pokemons[844] = "Cramorant";
    pokemons[845] = "Arrokuda";
    pokemons[846] = "Barraskewda";
    pokemons[847] = "Toxel";
    pokemons[848] = "Toxtricity";
    pokemons[849] = "Sizzlipede";
    pokemons[850] = "Centiskorch";
    pokemons[851] = "Clobbopus";
    pokemons[852] = "Grapploct";
    pokemons[853] = "Sinistea";
    pokemons[854] = "Polteageist";
    pokemons[855] = "Hatenna";
    pokemons[856] = "Hattrem";
    pokemons[857] = "Hatterene";
    pokemons[858] = "Impidimp";
    pokemons[859] = "Morgrem";
    pokemons[860] = "Grimmsnarl";
    pokemons[861] = "Obstagoon";
    pokemons[862] = "Perrserker";
    pokemons[863] = "Cursola";
    pokemons[864] = "Sirfetch'd";
    pokemons[865] = "Mr.Rime";
    pokemons[866] = "Runerigus";
    pokemons[867] = "Milcery";
    pokemons[868] = "Alcremie";
    pokemons[869] = "Falinks";
    pokemons[870] = "Pincurchin";
    pokemons[871] = "Snom";
    pokemons[872] = "Frosmoth";
    pokemons[873] = "Stonjourner";
    pokemons[874] = "Eiscue";
    pokemons[875] = "Indeedee";
    pokemons[876] = "Morpeko";
    pokemons[877] = "Cufant";
    pokemons[878] = "Copperajah";
    pokemons[879] = "Dracozolt";
    pokemons[880] = "Arctozolt";
    pokemons[881] = "Dracovish";
    pokemons[882] = "Arctovish";
    pokemons[883] = "Duraludon";
    pokemons[884] = "Dreepy";
    pokemons[885] = "Drakloak";
    pokemons[886] = "Dragapult";
    pokemons[887] = "Zacian";
    pokemons[888] = "Zamazenta";
    pokemons[889] = "Eternatus";
    pokemons[890] = "Kubfu";
    pokemons[891] = "Urshifu";
    pokemons[892] = "Zarude";
    pokemons[893] = "Regieleki";
    pokemons[894] = "Regidrago";
    pokemons[895] = "Glastrier";
    pokemons[896] = "Spectrier";
    pokemons[897] = "Calyrex";
}
