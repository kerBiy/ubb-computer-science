public class Main {

    // 1. ComplexNumber Class
    public static class ComplexNumber {
        private double re; // Real part
        private double im; // Imaginary part

        public ComplexNumber(double re, double im) {
            this.re = re;
            this.im = im;
        }

        public double getReal() {
            return re;
        }

        public double getImaginary() {
            return im;
        }

        public ComplexNumber add(ComplexNumber other) {
            return new ComplexNumber(this.re + other.re, this.im + other.im);
        }

        public ComplexNumber subtract(ComplexNumber other) {
            return new ComplexNumber(this.re - other.re, this.im - other.im);
        }

        public ComplexNumber multiply(ComplexNumber other) {
            return new ComplexNumber(this.re * other.re - this.im * other.im,
                    this.re * other.im + this.im * other.re);
        }

        public ComplexNumber divide(ComplexNumber other) {
            double denominator = other.re * other.re + other.im * other.im;
            return new ComplexNumber((this.re * other.re + this.im * other.im) / denominator,
                    (this.im * other.re - this.re * other.im) / denominator);
        }

        @Override
        public String toString() {
            return re + (im >= 0 ? " + " : " - ") + Math.abs(im) + " * i";
        }
    }

    // 2. Operation Enum
    public enum Operation {
        ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION;
    }

    // 3. ComplexExpression Class
    public abstract static class ComplexExpression {
        protected Operation operation;
        protected ComplexNumber[] args;

        public ComplexExpression(Operation operation, ComplexNumber[] args) {
            this.operation = operation;
            this.args = args;
        }

        public ComplexNumber execute() {
            ComplexNumber result = args[0];
            for (int i = 1; i < args.length; i++) {
                result = executeOneOperation(result, args[i]);
            }
            return result;
        }

        protected abstract ComplexNumber executeOneOperation(ComplexNumber a, ComplexNumber b);
    }

    // 4. Concrete Expression Classes
    public static class AdditionExpression extends ComplexExpression {
        public AdditionExpression(ComplexNumber[] args) {
            super(Operation.ADDITION, args);
        }

        @Override
        protected ComplexNumber executeOneOperation(ComplexNumber a, ComplexNumber b) {
            return a.add(b);
        }
    }

    public static class SubtractionExpression extends ComplexExpression {
        public SubtractionExpression(ComplexNumber[] args) {
            super(Operation.SUBTRACTION, args);
        }

        @Override
        protected ComplexNumber executeOneOperation(ComplexNumber a, ComplexNumber b) {
            return a.subtract(b);
        }
    }

    public static class MultiplicationExpression extends ComplexExpression {
        public MultiplicationExpression(ComplexNumber[] args) {
            super(Operation.MULTIPLICATION, args);
        }

        @Override
        protected ComplexNumber executeOneOperation(ComplexNumber a, ComplexNumber b) {
            return a.multiply(b);
        }
    }

    public static class DivisionExpression extends ComplexExpression {
        public DivisionExpression(ComplexNumber[] args) {
            super(Operation.DIVISION, args);
        }

        @Override
        protected ComplexNumber executeOneOperation(ComplexNumber a, ComplexNumber b) {
            return a.divide(b);
        }
    }

    // 5. ExpressionFactory Class
    public static class ExpressionFactory {
        private static ExpressionFactory instance;

        private ExpressionFactory() {}

        public static synchronized ExpressionFactory getInstance() {
            if (instance == null) {
                instance = new ExpressionFactory();
            }
            return instance;
        }

        public ComplexExpression createExpression(Operation operation, ComplexNumber[] args) {
            switch (operation) {
                case ADDITION:
                    return new AdditionExpression(args);
                case SUBTRACTION:
                    return new SubtractionExpression(args);
                case MULTIPLICATION:
                    return new MultiplicationExpression(args);
                case DIVISION:
                    return new DivisionExpression(args);
                default:
                    throw new IllegalArgumentException("Unknown operation");
            }
        }
    }

    // 6. ExpressionParser Class
    public static class ExpressionParser {
        public static ComplexExpression parse(String[] args) throws IllegalArgumentException {
            if (args.length < 3 || args.length % 2 == 0) {
                throw new IllegalArgumentException("Invalid expression format");
            }

            ComplexNumber[] complexNumbers = new ComplexNumber[(args.length + 1) / 2];
            Operation[] operations = new Operation[(args.length - 1) / 2];

            for (int i = 0, j = 0; i < args.length; i++) {
                if (i % 2 == 0) {
                    complexNumbers[j++] = parseComplex(args[i]);
                } else {
                    operations[(i - 1) / 2] = parseOperation(args[i]);
                }
            }

            ComplexExpression expression = null;
            for (int i = 0; i < operations.length; i++) {
                if (expression == null) {
                    expression = ExpressionFactory.getInstance().createExpression(operations[i],
                            new ComplexNumber[]{complexNumbers[i], complexNumbers[i + 1]});
                } else {
                    expression = ExpressionFactory.getInstance().createExpression(operations[i],
                            new ComplexNumber[]{expression.execute(), complexNumbers[i + 1]});
                }
            }

            return expression;
        }

        private static ComplexNumber parseComplex(String str) {
            str = str.replaceAll(" ", ""); // Remove spaces
            str = str.replace("i", ""); // Remove the 'i' for parsing
            String[] parts;
            double re = 0.0;
            double im = 0.0;

            if (str.contains("+")) {
                parts = str.split("\\+");
                re = Double.parseDouble(parts[0]);
                im = Double.parseDouble(parts[1]);
            } else if (str.contains("-")) {
                parts = str.split("(?=-)"); // Split at '-' while keeping the negative sign
                re = Double.parseDouble(parts[0]);
                im = parts.length > 1 ? Double.parseDouble(parts[1]) : 0.0;
            } else {
                re = Double.parseDouble(str);
            }

            return new ComplexNumber(re, im);
        }

        private static Operation parseOperation(String str) {
            switch (str.trim()) {
                case "+":
                    return Operation.ADDITION;
                case "-":
                    return Operation.SUBTRACTION;
                case "*":
                    return Operation.MULTIPLICATION;
                case "/":
                    return Operation.DIVISION;
                default:
                    throw new IllegalArgumentException("Unknown operator: " + str);
            }
        }
    }

    // Main Method
    public static void main(String[] args) {
        try {
            ComplexExpression expression = ExpressionParser.parse(args);
            ComplexNumber result = expression.execute();
            System.out.println("Result: " + result);
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}