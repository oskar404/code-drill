// Write a function that combines two lists by alternatingly taking elements.
// For example: given the two lists [a, b, c] and [1, 2, 3], the function should
// return [a, 1, b, 2, c, 3].

fn main() {
    let v1: Vec<String> =
        vec!["A".to_string(), "B".into(), "C".into(), "D".into()];
    let v2: Vec<String> =
        vec!["1".to_string(), "2".into(), "3".into(), "4".into(), "XX".into(),
            "YY".into()];
    let result = alternate(v1, v2);
    println!("{:?}", result);
}

fn alternate(v1: Vec<String>, v2: Vec<String>) -> Vec<String> {
    let mut result: Vec<String> = Vec::new();
    let mut i = 0;
    while i < v1.len() || i < v2.len() {
        if i < v1.len() {
            result.push(v1[i].clone());
        }
        if i < v2.len() {
            result.push(v2[i].clone());
        }
        i += 1;
    }
    result
}

