# 🎯 Hundir la Flota en Solitario - 8x8 LED Matrix

¡Bienvenido a la versión **en solitario** del clásico juego **“Hundir la Flota”**! ⚓🛳️  

Este proyecto utiliza una **matriz de LEDs 8x8 (1588 BS)** y un **joystick** para que el jugador pueda navegar y disparar a los barcos ocultos.  

## 🕹️ Cómo jugar
- Al iniciar la partida, los barcos se colocan **aleatoriamente** en la matriz, pero el jugador **no los ve**.  
- Usa el **joystick** para moverte por la cuadrícula.  
- Pulsa para **disparar** en la casilla seleccionada:  
  - 💡 **Acertaste:** el LED se enciende.  
  - ⚪ **Fallaste:** el LED queda apagado.  
- Tienes **5 vidas**. Cada fallo resta una vida.  
- Descubre todos los barcos antes de perder todas las vidas para **ganar**.  

## 🔄 Bucle de la partida
Cada partida sigue un loop sencillo y adictivo:  
1. Moverse por la matriz.  
2. Disparar a la casilla seleccionada.  
3. Verificar si aciertas o fallas.  
4. Actualizar vidas y LEDs.  
5. Repetir hasta ganar o perder.  

¡Prepárate para poner a prueba tu **estrategia y puntería**! 🎮⚓
