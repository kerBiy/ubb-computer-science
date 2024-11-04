package exceptions;

public class NoDataAvailableException extends Exception{
	
	private String message;
	
	public NoDataAvailableException(String message){
		super(message);
	}
	
	public String getMessage(){
		return message;
	}

}
