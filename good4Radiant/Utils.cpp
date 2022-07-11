#include "Utils.h"

std::string Utils::vec3string(vec3_t vector) {
	std::string finaltext;

	finaltext = std::to_string(vector[0]) + '\n' + std::to_string(vector[1]) + '\n' + std::to_string(vector[2]) + '\n';
	return finaltext;
}
void Utils::RegisterFont(const char* fontname)
{
	AddFontResourceEx(fontname, FR_PRIVATE, 0);

	D3DXCreateFont(game::dx->device, 20, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, fontname, &D3D::font1);
	D3DXCreateFont(game::dx->device, 20, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, fontname, &D3D::font1out);
}