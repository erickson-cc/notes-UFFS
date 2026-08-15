import pytest
from bank_account import BankAccount

def test_initial_balance():
    acc = BankAccount("Alice", 100.0)
    assert acc.balance == 100.0
    assert acc.owner == "Alice"

def test_deposit_valid():
    acc = BankAccount("Bob", 50.0)
    new_bal = acc.deposit(50.0)
    assert new_bal == 100.0
    assert acc.balance == 100.0

def test_invalid_owner():
    with pytest.raises(ValueError, match="Invalid owner name"):
        BankAccount("")
    with pytest.raises(ValueError, match="Invalid owner name"):
        BankAccount(000)

def test_negative_deposit():
    acc = BankAccount("Bob", 50.0)
    with pytest.raises(ValueError, match="Deposit amount must be positive"):
        acc.deposit(-100.0)
    with pytest.raises(ValueError, match="Deposit amount must be positive"):
        acc.deposit(0)

def test_account_freezing():
    acc = BankAccount("Bob", 50.0)
    acc.is_frozen = True
    with pytest.raises(PermissionError, match="Account is frozen"):
        acc.deposit(50.0)

def test_withdrawing_leq_zero():
    acc = BankAccount("Bob",50.0)
    with pytest.raises(ValueError, match="Invalid withdrawal amount"):
        acc.withdraw(0)
    with pytest.raises(ValueError, match="Invalid withdrawal amount"):
        acc.withdraw(-10.0)

def test_withdrawing_exceeding_amount():
    acc = BankAccount("Bob",50.0)
    with pytest.raises(ValueError, match="Invalid withdrawal amount"):
        acc.withdraw(51.0)

def test_withdrawing_frozen_account():
    acc = BankAccount("Bob",50.0)
    acc.is_frozen = True
    with pytest.raises(PermissionError, match="Account is frozen"):
        acc.withdraw(50)

def test_valid_withdraw():
    acc = BankAccount("Bob",50.0)
    new_bal = acc.withdraw(40.0)
    assert new_bal == 10
    assert acc.balance == 10
