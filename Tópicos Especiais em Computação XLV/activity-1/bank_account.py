class BankAccount:
    def __init__(self, owner: str, balance: float = 0.0):
        if not owner or not isinstance(owner, str):
            raise ValueError("Invalid owner name")
        self.owner = owner
        self.balance = float(balance)
        self.is_frozen = False

    def deposit(self, amount: float) -> float:
        if self.is_frozen:
            raise PermissionError("Account is frozen")
        if amount <= 0:
            raise ValueError("Deposit amount must be positive")
        self.balance += amount
        return self.balance

    def withdraw(self, amount: float) -> float:
        if self.is_frozen:
            raise PermissionError("Account is frozen")
        if amount <= 0 or amount > self.balance:
            raise ValueError("Invalid withdrawal amount")
        self.balance -= amount
        return self.balance
