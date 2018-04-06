// Write three functions that compute the sum of the numbers in a given list
// using a for-loop, a while-loop, and recursion.

fn main() {
    let l1: [i32; 10] = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34];
    println!("forloop(): {}", forloop(&l1));
    println!("whileloop(): {}", whileloop(&l1));
    println!("recursion(): {}", recursion(&l1, 0));
    println!("sum(): {}", sum(&l1));
}

fn forloop(list: &[i32]) -> i32 {
    let mut sum = 0;
    for i in list.iter() {
        sum += i;
    }
    sum
}

fn whileloop(list: &[i32]) -> i32 {
    let mut sum = 0;
    let mut i = 0;
    while i < list.len() {
        sum += list[i];
        i += 1;
    }
    sum
}

fn recursion(list: &[i32], i: usize) -> i32 {
    if i >= list.len() {
        return 0;
    }
    return list[i] + recursion(list, i+1);
}

// Rust has nice collection methods
fn sum(list: &[i32]) -> i32 {
    list.iter().sum()
}
