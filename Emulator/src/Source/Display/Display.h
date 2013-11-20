#ifndef _Display_h_
#define _Display_h_

#include <stdint.h>
#include "SDL.h"

struct PixelStruct_t
{
    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
};

class Display_t
{
    public:
        void Init( uint16_t xSize, uint16_t ySize );
        void Present( PixelStruct_t* pData );
        void DrawPixel( uint16_t xPos, uint16_t yPos, uint8_t red, uint8_t green, uint8_t blue );
        void Flip( void );
        
    private:
        void SurfaceLock( void );
        void SurfaceUnock( void );
        

    private:
        SDL_Surface* m_pSurface;
        uint16_t     m_SizeX;
        uint16_t     m_SizeY;
        
};

#endif