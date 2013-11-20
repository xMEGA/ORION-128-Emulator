#ifndef _Renderer_h_
#define _Renderer_h_

#include <stdint.h>

typedef  void ( *PresentLineCallBack_t )( void* pContext, uint8_t* pData, uint16_t lineNumber );    

class Renderer_t
{
    public:
          void RunFrame( uint8_t* memPage0, uint8_t* memPage1 );
          void SetPresentLineCallBack( void* pContext, PresentLineCallBack_t presentLineCallBack );
          void SwitchDisplay( uint8_t display );
          void SetVideoMode( uint8_t mode );


    private:

        void*   m_pContext;
        uint8_t m_LineBuff[ 384 * 3];

    private:
        PresentLineCallBack_t fp_PresentLineCallBack;

        
};

#endif