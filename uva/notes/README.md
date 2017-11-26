

## Non-Linear DS:

- Heap:
> Indexing: 
 ```
   left(x) : x << 1;
   right(x) : (x << 1) +1 ;
   parent(x) : x >> 1;
 ```

 - Usage: 
    1. partial_sort: O(nlogk) 

- BST:
> Check if valid BST: 
```
//INV: left < node <= right

checkBST(node) {
    int[] l = _range(node.left);
    int[] r = _range(node.right);

    return l.valid && r.valid && l.up < node && r.down >= node;
}

_range(node) int[] {
    if(node == NULL) {
        return int[](valid: true,up: MIN, down: MAX)
    }

    l = _range(node.left);
    r = _range(node.right);

    return int[](valid: l.valid && r.valid, up: max(r.up, node), down: min(l.down, node))
}

//Sol 2: (Recommended/In-order/No-duplicates) 
static prev = MIN;
inorder(node) bool {
    if(node == NULL) 
        return true;

    if(!inorder(node.left))
        return false;
    
    if(prev != NULL && prev.key >= node.key)
        return false;

    prev = node;
    return inorder(node.right);
}

//Sol 3: (Duplicates) 
inorder(node, toLeft) bool {
    if(node == NULL)
        return true;

    if(!inorder(node.left, true))
        return false;

    if(prev != NULL 
        && (toLeft && prev.key >= node.key
        ||  !toLeft && prev.key >node.key))
        return false;

    prev = node;
    return inorder(node.right);
}


```
> Output the elements in T in [a,b] ASC
```
sol(T node, a, b) {
    if(node == NULL) return;

    if(node.key IN [a.b]) {
        sol(node.left, a, b);

        print(node.key);

        sol(node.right, a, b);
    }

    return;
}

```

> Output all leaves DESC
```
sol(node) {
    if(node: isLeaf) {
        print node;
    } else {
        sol(node.right);
        sol(node.left);
    }
}

// O(n) traversal: all nodes must be traversed once
```


