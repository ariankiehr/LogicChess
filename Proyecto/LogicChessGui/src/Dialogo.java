/*  LogicChess: Herramienta didactica para el aprendizaje practico de la Logica de Primer Orden
 *  Copyright (C) 2011  Arian Kiehr, Matias Ariel Re Medina
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
import java.awt.*;
import javax.swing.*;

public class Dialogo {
	public static JDialog dameNuevoJDialog (Component p) {
		JDialog dialogo;
        Window vp = SwingUtilities.getWindowAncestor(p);
        if (vp instanceof Frame) dialogo = new JDialog((Frame) vp);
        else if (vp instanceof Dialog) dialogo = new JDialog((Dialog) vp);
        else dialogo = new JDialog();
        return dialogo;
	}
}
