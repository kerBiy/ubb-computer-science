import java.io.FileReader;
import java.io.IOException;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

public class JSONReader {

	public void readData() {
		JSONParser jsonParser = new JSONParser();
		try {
			Object obj = jsonParser.parse(new FileReader("./src/dogs.json"));
			JSONArray dogs = (JSONArray) obj;

			for (int i = 0; i < dogs.size(); i++) {
				JSONObject dog = (JSONObject) dogs.get(i);

				String name = (String) dog.get("name");
				Integer age = Integer.parseInt((String) dog.get("age"));
				Dog d = new Dog(name,age);
				System.out.println(d.getName()+" "+d.getAge());
			}

		} catch (IOException | ParseException e) {

			e.printStackTrace();
		}
	}
}
