import javax.swing.JFrame;
private static void createDefaultWindow(JFrame f) {
	JButton b1 = new JButton("Button");

	f.getContentPane().add(b1);
}
public static void Main(String[] args){
	JFrame frame = new JFrame("New Window");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setSize(300,300);

	createDefaultWindows(frame);
	frame.setVisible(true);
}


