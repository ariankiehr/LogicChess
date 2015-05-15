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
import java.awt.event.*;
import java.io.*;
import javax.swing.text.*;


public class Main extends JFrame implements ActionListener {

	public static final int TAM = 8; //tamano del tablero
	public static final int MAXLONGCAD = 280; //longitud formula
	private static String linuxDesktop = null;
	
	String nombresFichas[][] = new String[TAM][TAM];
	
	JLabel boton[][] = new JLabel[TAM][TAM];//tablero
	JLabel label=new JLabel("La formula es :");
	
	
	JPanel 
		panelBotones = new JPanel(),//para tablero
		panelPrincipal= new JPanel(),//para fondo del tablero
		panelFormula = new JPanel(),
		panelCheck = new JPanel();
	
	JTextField inFormula = new JTextField();
	
	JButton 
		vaciar = new JButton("Vaciar"), 
		ok = new JButton("Aceptar");
		
	JMenuBar menu = new JMenuBar();
	
	JMenu 
		archivo = new JMenu("Archivo"),
		ver = new JMenu("Ver"),
		ayuda = new JMenu("Ayuda");
	
	JMenuItem 
		nuevo = new JMenuItem("Nuevo"),
		salir = new JMenuItem("Salir"),
		personalizar = new JMenuItem("Personalizar"),
		itemayuda = new JMenuItem("Contenido"),
		acercade = new JMenuItem("Acerca De");
	
	JDialog Configuracion=null, //preferencias
	Decoracion=null; //personalizar
	
	static ImageIcon 
		torreblanca,
		caballoblanco,
		alfilblanco,
		reinablanca,
		reyblanco,
		peonblanco,
		torrenegra,
		caballonegro,
		alfilnegro,
		reinanegra,
		reynegro,
		peonnegro,
		none;
		
	ButtonGroup grupoBotonesOpcion, grupoBotonesColor;
	JTextField nombreFicha;
	
	int A,B;
	
	JButton[] botonPersonalizacion={
		new JButton("Fondo"),
		new JButton("Borde"),
		new JButton("Tablero Oscuro")
	};
	
	JRadioButton[] tiposDeFichas = {
		new JRadioButton("Peon"),
		new JRadioButton("Torre"),
		new JRadioButton("Caballo"),
		new JRadioButton("Alfil"),
		new JRadioButton("Reina"),
		new JRadioButton("Rey")
	};
	
	JRadioButton[] colorFichas = {
		new JRadioButton("Blanco"),
		new JRadioButton("Negro")
	};
	
	
	public static Color 
		azulClaro = new Color(76,76,204),
		celeste = new Color(80,80,200),
		azulOscuro = new Color(51,51,204),
		rojoClaro = new Color(255,76,76),
		marronMadera = new Color(206,92,0),
		grisClaro = new Color(204,204,204);
	
	GridBagLayout GBL = new GridBagLayout();
	GridBagConstraints GBC = new GridBagConstraints();
	
	
	public static void main(String[] args) {
		try{
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		}catch(Exception e) {e.printStackTrace();}
		new Main().setVisible(true);
	}
	
	
	
	public void inicArchivos() {
		try {
			File arch1 = new File("fichas.txt");
			arch1.deleteOnExit();
			arch1 = new File("formula.txt");
			arch1.deleteOnExit();
			FileWriter fichero = new FileWriter("fichas.txt");
			BufferedWriter bw = new BufferedWriter(fichero);
			bw.write("eof");
			bw.close();
			fichero = new FileWriter("formula.txt");
			bw = new BufferedWriter(fichero);
			bw.write("");
			bw.close();
		} catch(Exception e) {e.printStackTrace();}
	}
	
	public void cargarImagenes(){
		torreblanca = new ImageIcon("../resources/img/wR.png");
		caballoblanco = new ImageIcon("../resources/img/wN.png");
		alfilblanco = new ImageIcon("../resources/img/wB.png");
		reinablanca = new ImageIcon("../resources/img/wQ.png");
		reyblanco = new ImageIcon("../resources/img/wK.png");
		peonblanco = new ImageIcon("../resources/img/wP.png");
		torrenegra = new ImageIcon("../resources/img/bR.png");
		caballonegro = new ImageIcon("../resources/img/bN.png");
		alfilnegro = new ImageIcon("../resources/img/bB.png");
		reinanegra = new ImageIcon("../resources/img/bQ.png");
		reynegro = new ImageIcon("../resources/img/bK.png");
		peonnegro = new ImageIcon("../resources/img/bP.png");
		none = new ImageIcon("../resources/img/none.gif");
	}
	

	public Main() {
		super("LogicChess");
		this.setSize(800,770);
		this.setLocationRelativeTo(this);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		cargarImagenes();
		inicArchivos();
		this.setIconImage(peonblanco.getImage());
		panelBotones.setBorder(BorderFactory.createLineBorder(marronMadera,30));
		panelBotones.setLayout(new GridLayout(8,8));
		
		for(int a=0;a<TAM;a++) {
			for(int b=0;b<TAM;b++) {
				nombresFichas[a][b] = "";
				boton[a][b] = new JLabel();
				boton[a][b].addMouseListener(new EscucharMouse());
				boton[a][b].setOpaque(true);//para poder pintar el label
				boton[a][b].setHorizontalAlignment(JLabel.CENTER);
				boton[a][b].setIcon(none);
				panelBotones.add(boton[a][b]);
			}
		}
		
		label.setOpaque(true);
		nuevo.addActionListener(this);
		salir.addActionListener(this);
		personalizar.addActionListener(this);
		itemayuda.addActionListener(this);
		acercade.addActionListener(this);
		archivo.add(nuevo);
		archivo.addSeparator();
		archivo.add(salir);
		ver.add(personalizar);
		ayuda.add(acercade);
		ayuda.add(itemayuda);
		menu.add(archivo);
		menu.add(ver);
		menu.add(ayuda);
		setJMenuBar(menu);
		
		//coloca el tablero al medio sin posibilidad que se resize asi no se deforma
		panelPrincipal.setBackground(celeste);
		panelPrincipal.setLayout(GBL);
		GBC.ipadx =248;
		GBC.ipady=168;
		GBL.setConstraints(panelBotones, GBC);
		panelPrincipal.add(panelBotones);
		//fin colocacion panelbotones
		
		panelFormula.setLayout( new BoxLayout( panelFormula, BoxLayout.Y_AXIS ) );
		panelFormula.add(inFormula);
		
		inFormula.addActionListener(new ActionListener() {
   			public void actionPerformed(ActionEvent e) {
   				label.setText("La formula es :");
				goBackEnd();
   			}
		});
		
		inFormula.setDocument(new JTextFieldLimit(MAXLONGCAD));
		
		panelCheck.setLayout(new FlowLayout(FlowLayout.LEFT));
		Font newLabelFont=new Font(label.getFont().getName(),Font.BOLD,label.getFont().getSize());
 		label.setFont(newLabelFont);
		panelCheck.add(label);
		panelFormula.add(panelCheck);
		getContentPane().setLayout(new BorderLayout());
		getContentPane().add("Center" , panelPrincipal);
		getContentPane().add("South" , panelFormula);
		pintar();
	}
	
	public void pintar() {
		for(int a=0;a<TAM;a++) {
			for(int b=0;b<TAM;b++) {
				if(a%2==b%2) 
					boton[a][b].setBackground(Color.white);
				else  
					boton[a][b].setBackground(grisClaro);
			}
		}
	}
	
	//eventos sobre el tablero
	class EscucharMouse extends MouseAdapter {
		@Override
		public void mousePressed(MouseEvent evt) {
			Object SourceEvento = evt.getSource();
			for(int a=0;a<TAM;a++) {
				for(int b=0;b<TAM;b++) {
					if(SourceEvento==boton[a][b]) {
						apretoBoton(a,b, evt);
					}
				}
			}
		}
	}
	
	public void apretoBoton(int a, int b,MouseEvent Evento) {
		A=a;B=b;
		if (Configuracion==null) 
			CrearDialogoPreferencias(Evento);
		Configuracion.setVisible(true);
	}
	
	
	public int colorficha(int a, int b) {
		Icon Icono=boton[a][b].getIcon();
		//1=blanca -1=negra 0=vacio
		if( Icono==torreblanca || Icono==caballoblanco || Icono==alfilblanco || Icono==reyblanco ||
		Icono==reinablanca || Icono==peonblanco)return 0;
		if( Icono==torrenegra || Icono==caballonegro || Icono==alfilnegro || Icono==reynegro ||
		Icono==reinanegra || Icono==peonnegro)return 1;
		return 0;
	}
	
	public int tipoficha(int a, int b) {
		Icon Icono=boton[a][b].getIcon();
		if( Icono==torreblanca || Icono==torrenegra) return 2;
		if( Icono==caballoblanco || Icono==caballonegro) return 3;
		if( Icono==alfilblanco || Icono==alfilnegro) return 4;
		if( Icono==reyblanco || Icono==reynegro) return 6;
		if( Icono==reinablanca || Icono==reinanegra) return 5;
		if( Icono==peonblanco || Icono==peonnegro) return 1;
		return 0;
	}
	
	public void guardar() {
		FileWriter fichero = null;
		PrintWriter pw = null;
		try {
			fichero = new FileWriter("fichas.txt");
			pw = new PrintWriter(fichero);
			
			for (int i=0; i<TAM; i++) 
				for(int j=0; j<TAM; j++)
					if(boton[i][j].getIcon()!=none) 
						pw.println(tipoficha(i,j)+""+colorficha(i,j)+""+i+""+j+nombresFichas[i][j]);
			pw.println("eof");
			fichero.close();
			
			fichero = new FileWriter("formula.txt");
			pw = new PrintWriter(fichero);
			pw.write(inFormula.getText());
			pw.close();
			
		} catch (Exception e) { e.printStackTrace();}
	}
	
	//crea el dialogo de preferencia para la nueva ficha
	public void CrearDialogoPreferencias(MouseEvent Evento) {
		Configuracion = Dialogo.dameNuevoJDialog((Component)Evento.getSource());
		Configuracion.setTitle("Nueva Ficha");
	
		Configuracion.getContentPane().setLayout(new BoxLayout(Configuracion.getContentPane(), BoxLayout.PAGE_AXIS));
		grupoBotonesOpcion = new ButtonGroup();
		grupoBotonesColor = new ButtonGroup();
		nombreFicha = new JTextField();
		
		nombreFicha.addActionListener(new ActionListener() {
   			public void actionPerformed(ActionEvent e) {
   				nuevaFicha();
   			}
		});
		
		JPanel p = new JPanel(),
			   b = new JPanel(),
			   b1 = new JPanel();
		p.setLayout(new FlowLayout(FlowLayout.LEFT));
		b.setLayout(new BoxLayout(b, BoxLayout.PAGE_AXIS));
		b1.setLayout(new BoxLayout(b1, BoxLayout.PAGE_AXIS));
		
		for(int i=0; i<colorFichas.length; i++) {
			grupoBotonesColor.add(colorFichas[i]);
			b.add(colorFichas[i]);
		}
		colorFichas[0].setSelected(true);
		
		for(int x=0;x<tiposDeFichas.length;x++){
			grupoBotonesOpcion.add(tiposDeFichas[x]);
			b1.add(tiposDeFichas[x]);
		}
		tiposDeFichas[0].setSelected(true);
		
		p.add(b1);
		p.add(b);
		Configuracion.getContentPane().add(p);
		
		vaciar.addActionListener(this);
		ok.addActionListener(this);
		Configuracion.getContentPane().add(nombreFicha);
		JPanel p1 = new JPanel();
		p1.setLayout(new FlowLayout(FlowLayout.CENTER));
		p1.add(vaciar);
		p1.add(ok);
		Configuracion.getContentPane().add(p1);
		Configuracion.setResizable(false);
		Configuracion.pack();
		Configuracion.setLocationRelativeTo(this);
	}
	
	
	public void nuevo() {
		inicArchivos();
		for(int i=0; i<TAM; i++) {
			for(int j=0; j<TAM; j++) {
				boton[i][j].setIcon(none);
				boton[i][j].setToolTipText(null);
				nombresFichas[i][j] = "";
			}
		}
		inFormula.setText(null);
		label.setText("La formula es :");
		label.setForeground(null);
	}

	
	//eventos secundarios de la barra del menu
	public void actionPerformed(ActionEvent Evento) {
		Object SourceEvento = Evento.getSource();
		for(int x=0;x<botonPersonalizacion.length;x++) {
			if(SourceEvento==botonPersonalizacion[x]) {
				cambiarColor(x);
				Decoracion.dispose();
			}
		}
		if(SourceEvento==acercade) 
			creditos();
		else if(SourceEvento==nuevo)
			nuevo();
		else if(SourceEvento==salir) 
			System.exit(0);
		else if(SourceEvento==personalizar) 
			Personalizar(Evento);
		else if(SourceEvento==itemayuda) 
			Ayuda();
		else if(SourceEvento==vaciar) {
			quitarFicha();
		}
		else if(SourceEvento==ok)
			nuevaFicha();
	}
	
	public void quitarFicha() {
			boton[A][B].setIcon(none);
			boton[A][B].setToolTipText(null);
			nombresFichas[A][B] = "";
			Configuracion.setVisible(false);
	}
	
	public boolean esValido(String nombre) {
		boolean correcto = false;
		if(nombre.length()==2)
			if(nombre.charAt(0)=='c') 
				return true;
		return false;
	}
	
	public void nuevaFicha() {
		if(!nombreFicha.getText().equals("") && !existeNombre(nombreFicha.getText()) && esValido(nombreFicha.getText())) {
			nombresFichas[A][B] = nombreFicha.getText().toLowerCase();
			boton[A][B].setToolTipText(nombresFichas[A][B]);
			for(int i =0; i<tiposDeFichas.length;i++) {
				if(tiposDeFichas[i].isSelected()) {
					switch(i) {
						case 0: if(colorFichas[0].isSelected())
									boton[A][B].setIcon(peonblanco);
								else 
									boton[A][B].setIcon(peonnegro);
								break;
						case 1: if(colorFichas[0].isSelected())
									boton[A][B].setIcon(torreblanca);
								else 
									boton[A][B].setIcon(torrenegra);
								break;
						case 2: if(colorFichas[0].isSelected())
									boton[A][B].setIcon(caballoblanco);
								else 
									boton[A][B].setIcon(caballonegro); 
								break;
						case 3: if(colorFichas[0].isSelected())
									boton[A][B].setIcon(alfilblanco); 
								else 
									boton[A][B].setIcon(alfilnegro);
								break;
						case 4: if(colorFichas[0].isSelected())
									boton[A][B].setIcon(reinablanca);
								else 
									boton[A][B].setIcon(reinanegra);
								break;
						case 5: if(colorFichas[0].isSelected())
									boton[A][B].setIcon(reyblanco);
								else 
									boton[A][B].setIcon(reynegro); 
								break;
						default: boton[A][B].setIcon(none);
					}
				}
			}     
			Configuracion.setVisible(false);
		}
	}
	
	public boolean existeNombre(String nombre) {
		for(int i=0; i<TAM; i++)
			for(int j=0; j<TAM; j++)
				if(nombresFichas[i][j].equals(nombre) && ( i!=A || j!=B ))
					return true;
		return false;
	}
	
	
	public void goBackEnd() {
		guardar();
		try {
			Process p = null;
			if (System.getProperty("os.name").toUpperCase().indexOf("WINDOWS") != -1)
				p = Runtime.getRuntime().exec("LogicChess.exe fichas.txt formula.txt");
			if (System.getProperty("os.name").toUpperCase().indexOf("LINUX") != -1 )
				p = Runtime.getRuntime().exec("./LogicChess fichas.txt formula.txt");
			p.waitFor();
			InputStream is = p.getInputStream();
            BufferedReader br = new BufferedReader (new InputStreamReader (is));
            String valor = "", form = "";
            valor = br.readLine();
            form = br.readLine();
            getValor(valor, form);
		}catch (Exception e){e.printStackTrace();}
	}
	
	public void getValor(String linea, String form) {
		try {	
			if(linea.equals("1")) {
				label.setText(form + " : es Valida");
				label.setForeground(new Color(34,177,76));
			}
			else if(linea.equals("0")){
				label.setText(form + " : es Falsa");
				label.setForeground(new Color(255,128,64));
			}
			else {
				label.setText(inFormula.getText() + " : es Erronea");
				label.setForeground(Color.RED);
			}
		} catch(Exception e) {e.printStackTrace();}
	}
	
	
	public void Ayuda() {
		String pathAyuda = System.getProperty("user.dir").replace("classes","resources/Ayuda.pdf");
		File pdfFile = new File(pathAyuda);
		try {
			if (Desktop.isDesktopSupported()) 
				Desktop.getDesktop().open(pdfFile);
			else
				JOptionPane.showMessageDialog(null,"El manual se encuentra en la carpeta resources","Ayuda", JOptionPane.INFORMATION_MESSAGE);		
		} catch (IOException e) {
			JOptionPane.showMessageDialog(null,"El manual se encuentra en la carpeta resources","Ayuda", JOptionPane.INFORMATION_MESSAGE);
			e.printStackTrace();
		}
	}
	
	public void cambiarColor(int Codigo) {
		switch(Codigo){
			case 0 : celeste = JColorChooser.showDialog(this, "Seleccione un nuevo color...", celeste);
					panelPrincipal.setBackground(celeste);
					break;
			case 1 : marronMadera = JColorChooser.showDialog(this, "Seleccione un nuevo color...", marronMadera);
					panelBotones.setBorder(BorderFactory.createLineBorder(marronMadera,30));
					break;
			case 2 : grisClaro = JColorChooser.showDialog(this, "Seleccione un nuevo color...", grisClaro);
					break;
			case 3 : azulClaro = JColorChooser.showDialog(this, "Seleccione un nuevo color...", azulClaro);
					break;
			case 4 : azulOscuro = JColorChooser.showDialog(this, "Seleccione un nuevo color...", azulOscuro);
					break;
			case 5 : rojoClaro = JColorChooser.showDialog(this, "Seleccione un nuevo color...", rojoClaro);
					break;
		}
		pintar();
	}
	
	
	//crea el dialogo de personalizacion
	public void CrearDialogoPersonalizar(ActionEvent Evento) {
		Decoracion = Dialogo.dameNuevoJDialog((Component)Evento.getSource());
		Decoracion.setTitle("Cambiar Color De:");
		Decoracion.getContentPane().setLayout(new FlowLayout(FlowLayout.CENTER));
		
		for(int x=0;x<botonPersonalizacion.length;x++){
			botonPersonalizacion[x].addActionListener(this);
			Decoracion.getContentPane().add(botonPersonalizacion[x]);
		}
		
		Decoracion.setResizable(false);
		Decoracion.pack();
		Decoracion.setLocationRelativeTo(this);
	}
	
	
	
	public void Personalizar(ActionEvent Evento) {
		if (Decoracion==null) 
			CrearDialogoPersonalizar(Evento);
		Decoracion.setVisible(true);
	}
	
	
	public void creditos() {
		JOptionPane.showMessageDialog(null,
			"Herramienta didactica para el aprendizaje practico de la Logica de Primer Orden\n\n"+
			"Desarrollada por:\n"+
			"Arian Kiehr\n"+
			"Matias Ariel Re Medina\n\n"+
			"Se encuentra bajo licencia GPL."
			,"LogicChess", JOptionPane.INFORMATION_MESSAGE);
	}
	
	
	private static String getLinuxDesktop(){
		if(linuxDesktop!=null) 
			return linuxDesktop;
		if(System.getenv("GNOME_DESKTOP_SESSION_ID")==null || System.getenv("GNOME_KEYRING_SOCKET")==null)
			linuxDesktop="gnome";
		else if(System.getenv("KDE_FULL_SESSION")==null || System.getenv("KDE_MULTIHEAD")==null)
			linuxDesktop="kde";
		else 
			linuxDesktop="";
		return linuxDesktop;
	}
	
}

//Para limitar la cantidad de caracteres que entran en la formula
class JTextFieldLimit extends PlainDocument {
    private int limit;
    private boolean toUppercase = false;
    
    JTextFieldLimit(int limit) {
        super();
        this.limit = limit;
    }
    
    JTextFieldLimit(int limit, boolean upper) {
        super();
        this.limit = limit;
        toUppercase = upper;
    }
    
    public void insertString
            (int offset, String  str, AttributeSet attr)
            throws BadLocationException {
        if (str == null) return;
        
        if ((getLength() + str.length()) <= limit) {
            if (toUppercase) str = str.toUpperCase();
            super.insertString(offset, str, attr);
        }
    }
}

