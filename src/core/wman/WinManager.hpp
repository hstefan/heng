/**********************************************************************************
 * Copyright (C) 2011 by Hugo Stefan Kaus Puhlmann                                *
 * Permission is hereby granted, free of charge, to any person obtaining a copy   *
 * of this software and associated documentation files (the "Software"), to deal  *
 * in the Software without restriction, including without limitation the rights   *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
 * copies of the Software, and to permit persons to whom the Software is          * 
 * furnished to do so, subject to the following conditions:                       *
 *                                                                                *
 * The above copyright notice and this permission notice shall be included in     *
 * all copies or substantial portions of the Software.                            *
 *                                                                                *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN      *
 * THE SOFTWARE.                                                                  *
 *********************************************************************************/

/*
 * Nome: Hugo Stefan Kaus Puhlmann
 * Matricula: 2910182
 */

#ifndef HSTEFAN_CORE_WIN_MANAGER_HPP
#define HSTEFAN_CORE_WIN_MANAGER_HPP

namespace hstefan
{
namespace core
{
namespace wman
{
/**
 * Classe para abstrata para manipular o main loop de aplica��es gr�ficas.
 */
class WinManager
{
public:
   /**
    * Fun��o que deve ser sobreescrita para realisar opera��es de atualiza��o, 
    * de acordo com o tempo especificado no construtor.
    */
   virtual void onUpdate() 
   { /* Por padr�o, a fun��o onUpdate n�o faz nada. */ }
   
   /**
    * Fun��o que deve ser sobreescrita para realisar opera��es de renderiza��o, 
    * de acordo com o tempo especificado no construtor.
    */
   virtual void onRender() = 0;
   
   /**
    * Fun��o chamada ap�s t�rmino do main loop.
    */
   virtual void onDestroy()
   { /* Por padr�o, n�o faz nada. */}

   /**
    * Fun��o chamada quando o programa come�a a rodar.
    */
   virtual void onStart()
   { /*Por padr�o, n�o faz nada*/ }

   /**
    * Fun��o que vai "dizer" quando o programa p�ra, o teste ser� feito ap�s cada
    * chamada da fun��o onUpdate.
    */
   virtual bool isDone() = 0;

   /**
    * Fun��o que inicia o loop principal.
    */
   void run();

   /**
    * @param fps Frames per second.
    * @param ups Updates per second.
    */
   WinManager(float fps, float ups);

protected:
   double fps;
   double ups;
};

} //namespace wman
} //namespace core
} //namespace hstefan

#endif