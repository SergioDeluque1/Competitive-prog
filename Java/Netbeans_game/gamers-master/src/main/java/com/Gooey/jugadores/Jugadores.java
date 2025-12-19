package com.Gooey.jugadores;

import com.Gooey.jugadores.Players;
import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.GroupLayout;
//import javax.swing.*;

public final class Jugadores {
    
    static Scanner sc = new Scanner(System.in);
    static ArrayList<Jugadores> gamers = new ArrayList<>();

    public static void main(String[] args) {
        
        
        //JFrame scrn = new JFrame();
        FrmGui1 scrn = new FrmGui1();
        scrn.setSize(500, 300);
        scrn.setVisible(true);
        // char rta = 'y';
        //System.out.println("desea iniciar programa [y][n] ");
        //rta = sc.next().charAt(0);
        while ('y' == 'y') {
            agregarJugador();
            listarJugadores();
            //System.out.println("Digite el id del jugador a eliminar");
            //System.out.println("si no desea eliminar jugador, digite '-1' ");
            int id = 0;
            eliminarJugador(id);
            listarJugadores();
            //System.out.println("Digite el id del jugador a encontrar");
            if (id != -1)
                mostrarJugador(id);
        // System.out.println("desea iniciar programa [y][n] ");
         //rta = sc.next().charAt(0);*/
        }
    }

    
    static void agregarJugador() {

        char rpta = 'y';

        do {
           // System.out.println("Dese adicionar un jugador [y]|[n]: ");
            rpta = sc.next().charAt(0);

            if (rpta == 'y') {
                String usr = null;
                Players gamer = new Players();
                //System.out.println("Digite el nombre para el jugador: ");
                gamer.setNombre(usr);

                //System.out.println("Digite el nivelpara el jugador: \n"
                //        + "'P'principiante, 'I' intermedio, 'A' Avanzado");
                char lvl = 'P';
                gamer.setNivel(lvl);
                //System.out.println("Digite el Juego favorito para el jugador: ");
                gamer.setJuegofavorito(sc.next());

                gamer.setId((int) (Math.random() * 1000 + 1));
                gamer.setMax_score((int) (Math.random() * 10000 + 1));
                Jugadores.add(gamer);//adicionamos el jugar
            }
        } while (rpta == 'y');//condición q control el ciclo

    }

    static void eliminarJugador(int id) {
        for (Jugadores Players : gamers) {
            Players jugador = new Players();
            if (jugador.getId() == id) {
                gamers.remove(jugador);//elimina el objeto actual q coincide con el id
                break;//se sale del ciclo
            }//end if

        }//end for
        //System.out.println("Se ha eliminado al Jugador con id: " + id);
    }

    static void editarJugador(int id) {
        for (Jugadores player : gamers) {
            Players jugador = new Players();
            //System.out.println("Jugador: " + jugador.getNombre()
             //       + " id: " + jugador.getId());
        }
    }

    static void mostrarJugador(int id) {
        for (Jugadores Players : gamers) {
            Players jugador = new Players();
            if (jugador.getId() == id) {
                //System.out.println("Se ha encontrado al Jugador: " + jugador.getNombre()
                     //   + " id: " + jugador.getId());
                break;//se sale del ciclo
            }//end if
        }//end for
    }//end method

    static void listarJugadores() {
        for (Jugadores Players : gamers) {
            Players jugador = new Players();
           // System.out.println("Jugador: " + jugador.getNombre()
                    //+ " id: " + jugador.getId());
        }

    }

    private static void add(Players gamer) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

}
