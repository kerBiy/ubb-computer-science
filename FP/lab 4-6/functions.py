# /----- Adding -----/


def addExpense(
    expenses: list[dict], apartment: int, val: float, type: str, date: str
) -> None:
    expenses.append({"apartment": apartment, "val": val, "type": type, "date": date})


def modifyExpenseAtApartment(
    expenses: list[dict], id: int, apartment: int, val: float, type: str, date: str
) -> None:
    id -= 1
    expenses[id]["apartment"] = apartment
    expenses[id]["val"] = val
    expenses[id]["type"] = type
    expenses[id]["date"] = date


# /----- Deleting -----/


def deleteAllExpensesFrom(expenses: list[dict], apartment: int) -> None:
    expenses[:] = [expense for expense in expenses if expense["apartment"] != apartment]


def deleteConsecutiveExpensesFrom(
    expenses: list[dict], apartment_start: int, apartment_end: int
) -> None:
    expenses[:] = [
        expense
        for expense in expenses
        if not apartment_start <= expense["apartment"] <= apartment_end
    ]


def deleteExpensesOfType(expenses: list[dict], type: str) -> None:
    expenses[:] = [expense for expense in expenses if expense["type"] != type]


# /----- Searching -----/


def allApartmentsWithExpensesHigherThan(expenses: list[dict], val: float) -> list[int]:
    return [expense["apartment"] for expense in expenses if expense["val"] >= val]


def allExpensesOfType(expenses: list[dict], type: str) -> list[dict]:
    return [expense for expense in expenses if expense["type"] == type]


def allExpensesBeforeDateBiggerThanVal(
    expenses: list[dict], date: str, val: float
) -> list[dict]:
    return [
        expense
        for expense in expenses
        if expense["date"] < date and expense["val"] > val
    ]


# /----- Printing -----/


def sumExpensesOfType(expenses: list[dict], type: str) -> float:
    return sum(expense["val"] for expense in expenses if expense["type"] == type)


def sortApartmentsByType(expenses: list[dict], type: str) -> list[int]:
    val_map = {}

    for expense in expenses:
        if expense["type"] == type:
            val_map[expense["apartment"]] = (
                val_map.get(expense["apartment"], 0) + expense["val"]
            )

    return sorted(val_map)


def totalExpensesForApartment(expenses: list[dict], apartment: int) -> float:
    return sum(
        expense["val"] for expense in expenses if expense["apartment"] == apartment
    )


# /----- Filtering -----/


# def eliminateAllExpensesOfType(expenses: list[dict], type: str) -> None:
#     expenses[:] = [expense for expense in expenses if expense["type"] != type]


def eliminateAllExpensesLowerThan(expenses: list[dict], val: float) -> None:
    expenses[:] = [expense for expense in expenses if expense["val"] > val]
