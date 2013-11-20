#include "Display.h"

void Display_t::SurfaceLock( void )
{
    if ( SDL_MUSTLOCK( m_pSurface ) )
    { 
        if ( SDL_LockSurface( m_pSurface ) < 0 )
        { 
            return; 
        } 
    } 
}

void Display_t::SurfaceUnock( void )
{
   if ( SDL_MUSTLOCK( m_pSurface ) )
   { 
       SDL_UnlockSurface( m_pSurface ); 
   } 
}

void Display_t::Init( uint16_t xSize, uint16_t ySize )
{
    SDL_Init( SDL_INIT_VIDEO );
    
    m_SizeX = xSize;
    m_SizeY = ySize;
    
    m_pSurface = SDL_SetVideoMode( m_SizeX, m_SizeY, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE );
}

void Display_t::Present( PixelStruct_t* pData )
{
    uint32_t* pBuff = (uint32_t *)m_pSurface->pixels; 
    
    SurfaceLock();

    for( uint32_t i = 0; i != m_SizeX * m_SizeY ; i++)
    { 
         *pBuff ++= SDL_MapRGB( m_pSurface->format, pData->Red, pData->Green, pData->Blue ); 
          pData ++;
    } 

    SurfaceUnock();
    SDL_Flip( m_pSurface );
}
        
void Display_t::DrawPixel( uint16_t xPos, uint16_t yPos, uint8_t red, uint8_t green, uint8_t blue )
{
    uint32_t* bufp = (uint32_t *)m_pSurface->pixels + yPos * m_pSurface->pitch / 4 + xPos; 
    uint32_t  color = SDL_MapRGB( m_pSurface->format, red, green, blue ); 
    *bufp = color; 
}

void Display_t::Flip( void )
{
    SDL_Flip( m_pSurface );
}