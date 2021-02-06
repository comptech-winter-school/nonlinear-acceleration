

#pragma once

#include <vector>

size_t intervals = 25; //количество интервалов
double interval = 5.9; //сам интервал
size_t deg = 7;		   //степень полиномов


const vector<vector<double>> A = {  //Значения констант
{
-0x1.b5d18fb873e52p-40 ,
0x1.20dd7507b0082p0 ,
-0x1.309d7c524ea38p-24 ,
-0x1.8126aacb1b3ep-2 ,
-0x1.36168d4006d32p-15 ,
0x1.cf76c9f371726p-4 ,
-0x1.6c641452d6f03p-10 ,
-0x1.8b8dee801625ap-6 ,
},

{
-0x1.18b7ad045c78dp-19 ,
0x1.20e0b7a050c24p0 ,
-0x1.0c3741548f8e2p-11 ,
-0x1.7e1e029892821p-2 ,
-0x1.59b9fdf0863d8p-7 ,
0x1.16fbe95ff06e1p-3 ,
-0x1.f708d7b490063p-6 ,
-0x1.e013a9eaae9fbp-8 ,
},

{
-0x1.058f76acc14cep-13 ,
0x1.21500c611723dp0 ,
-0x1.5eca618aa52abp-7 ,
-0x1.5ae4e4f3eee98p-2 ,
-0x1.4c5a8ec0b6095p-4 ,
0x1.cba03a80de824p-3 ,
-0x1.7c7991b3cc7ecp-4 ,
0x1.818f4033e6d91p-7 ,
},

{
-0x1.2f3b2e11258a8p-11 ,
0x1.22803e339a0d7p0 ,
-0x1.fe80bcc93e85p-6 ,
-0x1.275fda5afacc7p-2 ,
-0x1.3ef86db01c666p-3 ,
0x1.2a182afe00a8cp-2 ,
-0x1.0257a3b11c09fp-3 ,
0x1.35b5d8e8629b7p-6 ,
},

{
0x1.49c7c58e8861ap-8 ,
0x1.185397cee32e8p0 ,
0x1.6f90c3d129d22p-4 ,
-0x1.f90558c1b3338p-2 ,
0x1.b0065ef27c893p-5 ,
0x1.4eb25251ca37dp-3 ,
-0x1.524e6ba0f1a72p-4 ,
0x1.9a48889919de7p-7 ,
},

{
0x1.541399a929a0bp-5 ,
0x1.c357a51e0b24fp-1 ,
0x1.40c081d8edf24p-1 ,
-0x1.3e9f42d22e3e2p0 ,
0x1.5ef95f22c1e49p-1 ,
-0x1.41ab94fbdc787p-3 ,
0x1.001504e1b7c6cp-7 ,
0x1.99b389c5e3256p-10 ,
},

{
0x1.d742406664d9dp-4 ,
0x1.08a79fe264665p-1 ,
0x1.6711d1d31f133p0 ,
-0x1.14ffd3f6619ebp1 ,
0x1.571342f601b36p0 ,
-0x1.bfb3674b59d3ap-2 ,
0x1.314547c7103b8p-4 ,
-0x1.588c92a208bb3p-8 ,
},

{
0x1.f73a33291492bp-4 ,
0x1.e72ae603fbe2fp-2 ,
0x1.7dfda79d694bap0 ,
-0x1.227e1911ca351p1 ,
0x1.69c6e0f2badd8p0 ,
-0x1.de5b05fc76e7cp-2 ,
0x1.4cde9cbfa3154p-4 ,
-0x1.82c20a8b55d48p-8 ,
},

{
-0x1.ca7448e56564dp-4 ,
0x1.5647d265c86a1p0 ,
0x1.185ddfe14e2a1p-3 ,
-0x1.156cba12c4e9cp0 ,
0x1.948c1b2ba122p-1 ,
-0x1.1507ae8f34c7fp-2 ,
0x1.7f21950a6da9dp-5 ,
-0x1.b12a77baf0c7ap-9 ,
},

{
-0x1.35d9a12b1542cp-1 ,
0x1.7b0bcedca0f3cp1 ,
-0x1.141f1d6bd584ap1 ,
0x1.6f85e6697aa4ep-1 ,
-0x1.e6340a939c264p-5 ,
-0x1.ebab391e04b76p-6 ,
0x1.23bdeebc25837p-7 ,
-0x1.882fe292840bfp-11 ,
},

{
-0x1.14ed094d1f493p0 ,
0x1.187e48685c383p2 ,
-0x1.fcd550de1075ap1 ,
0x1.0158206871d18p1 ,
-0x1.38ea95c32d868p-1 ,
0x1.c8556a14fd2fdp-4 ,
-0x1.706e87899f9d6p-7 ,
0x1.fa384f7d13d0bp-12 ,
},

{
-0x1.32d3fef5e91p0 ,
0x1.2d4bbe3c41c5fp2 ,
-0x1.17378cb6e3f0fp2 ,
0x1.222f54daae6b1p1 ,
-0x1.6d15def942d0dp-1 ,
0x1.15e071439f6bfp-3 ,
-0x1.d9a9d5f16b218p-7 ,
0x1.5c8eec5df979ep-11 ,
},

{
-0x1.bb19a5306de5dp-1 ,
0x1.f1e967b6f4e91p1 ,
-0x1.c0409e03c7211p1 ,
0x1.c3764c90b32c5p0 ,
-0x1.128f793813591p-1 ,
0x1.931fa1f7dd6cap-4 ,
-0x1.4aa3a0269c36fp-7 ,
0x1.d3456e3560eap-12 ,
},

{
-0x1.22e8c306153p-2 ,
0x1.4822591801b61p1 ,
-0x1.1a2ceda264d66p1 ,
0x1.0ee2c72586f33p0 ,
-0x1.396bf0ebd63a6p-2 ,
0x1.b4ed94d5c2d08p-5 ,
-0x1.53a99f2d96a8ep-8 ,
0x1.c63bea09267ccp-13 ,
},

{
0x1.17e31e86cc761p-2 ,
0x1.613b6d8261a3dp0 ,
-0x1.20765d419db2dp0 ,
0x1.06995679e7375p-1 ,
-0x1.1fbcca8c6525cp-3 ,
0x1.7b68a8f0673d7p-6 ,
-0x1.16ab0ba6a1673p-9 ,
0x1.5fbbadd115788p-14 ,
},

{
0x1.50d112ab2eaf3p-1 ,
0x1.3bbd603b75744p-1 ,
-0x1.e8fcf0f16f36ep-2 ,
0x1.a5b2f015d3ba9p-3 ,
-0x1.b559bf854dd66p-5 ,
0x1.10b3b96e9fb85p-7 ,
-0x1.7a949205e70ap-11 ,
0x1.c349374bdd419p-16 ,
},

{
0x1.baadcecca6c31p-1 ,
0x1.da640ef92b164p-3 ,
-0x1.5c75cf47877b9p-3 ,
0x1.1ce14952fc3c1p-4 ,
-0x1.17ecd437d3337p-6 ,
0x1.4a8f8be9e5fb6p-9 ,
-0x1.b25688f602b5fp-13 ,
0x1.e9d07a47fd76p-18 ,
},

{
0x1.e8c1e4c3507ecp-1 ,
0x1.2e46a31540dbbp-4 ,
-0x1.a5c2b09613a3ap-5 ,
0x1.4757d624d13d1p-6 ,
-0x1.313cea44499b5p-8 ,
0x1.55ef4ccf13bd6p-11 ,
-0x1.aa0e65f67a508p-15 ,
0x1.c77dd625ecbe1p-20 ,
},

{
0x1.f95a341fb063ep-1 ,
0x1.4914db5522ab4p-6 ,
-0x1.b4cc88c9bfcb3p-7 ,
0x1.426802306eb46p-8 ,
-0x1.1dd367915e5c7p-10 ,
0x1.30565d84b1a96p-13 ,
-0x1.68592786fcc2ap-17 ,
0x1.6dfff626529cbp-22 ,
},

{
0x1.fe5e7e94e5a6dp-1 ,
0x1.33d1da7bdd236p-8 ,
-0x1.855c58ff608a5p-9 ,
0x1.11d0a8314c9b3p-10 ,
-0x1.ce777be2fe519p-13 ,
0x1.d4f8ebf44a71fp-16 ,
-0x1.085ffa4ff4159p-19 ,
0x1.ff4bc9692ac13p-25 ,
},

{
0x1.ffa7bbb8849c3p-1 ,
0x1.f119aef1a5eeep-11 ,
-0x1.2c22f9d1786f9p-11 ,
0x1.92ef34c0d264ap-13 ,
-0x1.44bec7834e1ebp-15 ,
0x1.3a3de06749727p-18 ,
-0x1.520961f75ffb2p-22 ,
0x1.37d6861d8d374p-27 ,
},

{
0x1.ffefdb370d3d3p-1 ,
0x1.5bd4fa2db35e3p-13 ,
-0x1.91add8593607fp-14 ,
0x1.01d218e7b2492p-15 ,
-0x1.8d56ab7e53511p-18 ,
0x1.6f91f7e957fd8p-21 ,
-0x1.79f7e1f0ab025p-25 ,
0x1.4d44d13c1de7cp-30 ,
},

{
0x1.fffd6feb6b02ap-1 ,
0x1.a73355ee00acbp-16 ,
-0x1.d426f638cab3p-17 ,
0x1.1fd155ff753b6p-18 ,
-0x1.a8d47e71aa2bep-21 ,
0x1.785e94d1dcfcp-24 ,
-0x1.729bd56b697e3p-28 ,
0x1.38e71e2e0ab36p-33 ,
},

{
0x1.ffffa55740ff3p-1 ,
0x1.c0e51fa416fa2p-19 ,
-0x1.dc70866d7b491p-20 ,
0x1.1903f5a93b08bp-21 ,
-0x1.8dea70154fecap-24 ,
0x1.5229bf12b9c2ap-27 ,
-0x1.3f66d9d67b274p-31 ,
0x1.02a6f788bc835p-36 ,
},

{
0x1.fffff5119761fp-1 ,
0x1.a018e645eacb4p-22 ,
-0x1.a85bff4701f71p-23 ,
0x1.e0fe23f02070fp-25 ,
-0x1.47307dda4d7e6p-27 ,
0x1.0b246aa714911p-30 ,
-0x1.e4cf55b457d2p-35 ,
0x1.792762136e61ap-40 ,
},

};
