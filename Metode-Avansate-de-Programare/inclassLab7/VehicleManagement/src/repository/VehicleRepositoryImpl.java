package repository;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.util.Properties;

import domain.Vehicle;
import utils.MileageUnit;
import utils.IOHandler;

public class VehicleRepositoryImpl implements VehicleRepository {
	private List<Vehicle> vehicles;

	public VehicleRepositoryImpl() {
		this.vehicles = new ArrayList<>();
	}

	public List<Vehicle> getVehicles() {
		return vehicles;
	}

	@Override
	public void deleteVehicle(Vehicle vehicle) {
		Integer currentYear = Calendar.getInstance().get(Calendar.YEAR);

		if ((currentYear - vehicle.getYear()) > 30) {
			// we will delete the vehicle, mark it as being inactive
			vehicle.setInactive();
		}
	}

	public void initialLoadOfVehicles(String property) {
		// read from a text file the vehicle information
		BufferedReader bufferedReader = null;
		try {
			bufferedReader=IOHandler.initializeBufferReader(property);
			String line;
			while ((line = bufferedReader.readLine()) != null) {
				String[] arguments = line.split(",");
				String mileageUnit = arguments[3];
				MileageUnit vehicleMileageUnit;

				// determines the mileage unit from text file
				if (MileageUnit.KM.equals(mileageUnit)) {
					vehicleMileageUnit = MileageUnit.KM;
				} else {
					vehicleMileageUnit = MileageUnit.MILE;
				}

				Vehicle vehicle = new Vehicle(arguments[0], Double.parseDouble(arguments[1]),
						Integer.parseInt(arguments[2]), vehicleMileageUnit);
				vehicles.add(vehicle);
			}

		} catch (IOException e) {
			System.out.println("Errors while loading data from text file:" + e.getStackTrace());
		} finally {
			try {
				bufferedReader.close();
			} catch (IOException e) {
				System.out.println("Errors while closing the buffer:" + e.getStackTrace());
			}
		}
	}
}
