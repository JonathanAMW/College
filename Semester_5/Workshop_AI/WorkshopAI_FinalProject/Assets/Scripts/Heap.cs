using UnityEngine;
using System.Collections;
using System;

// Generic Heap class that works with types implementing the IHeapItem interface
public class Heap<T> where T : IHeapItem<T> {
    
    // Array to hold heap elements and a count tracker
    T[] items;
    int currentItemCount;

    // Constructor initializing the heap with a specified maximum size
    public Heap(int maxHeapSize) {
        items = new T[maxHeapSize];
    }

    // Add an item to the heap
    public void Add(T item) {
        item.HeapIndex = currentItemCount; // Set the index of the added item
        items[currentItemCount] = item; // Add the item to the end of the array
        SortUp(item); // Sort the item upwards in the heap
        currentItemCount++; // Increment the count of items in the heap
    }

    // Remove the first (highest priority) item from the heap
    public T RemoveFirst() {
        T firstItem = items[0]; // Get the first item
        currentItemCount--; // Decrement the count of items
        items[0] = items[currentItemCount]; // Move the last item to the root
        items[0].HeapIndex = 0; // Update its index
        SortDown(items[0]); // Sort it down in the heap
        return firstItem; // Return the removed item
    }

    // Update the position of an item in the heap
    public void UpdateItem(T item) {
        SortUp(item); // Sort the item upwards in the heap
    }

    // Get the count of items in the heap
    public int Count {
        get {
            return currentItemCount;
        }
    }

    // Check if the heap contains a specific item
    public bool Contains(T item) {
        return Equals(items[item.HeapIndex], item);
    }

    // Sort an item down in the heap
    void SortDown(T item) {
        // Loop to sort down the item in the heap
        while (true) {
            int childIndexLeft = item.HeapIndex * 2 + 1;
            int childIndexRight = item.HeapIndex * 2 + 2;
            int swapIndex = 0;

            // Check if left child index is within the heap bounds
            if (childIndexLeft < currentItemCount) {
                swapIndex = childIndexLeft;

                // Check if right child index is within bounds and compare children
                if (childIndexRight < currentItemCount) {
                    if (items[childIndexLeft].CompareTo(items[childIndexRight]) < 0) {
                        swapIndex = childIndexRight; // Set swap index to the right child
                    }
                }

                // Compare item with its highest priority child and swap if necessary
                if (item.CompareTo(items[swapIndex]) < 0) {
                    Swap(item, items[swapIndex]); // Swap the items
                }
                else {
                    return;
                }
            }
            else {
                return;
            }
        }
    }

    // Sort an item up in the heap
    void SortUp(T item) {
        int parentIndex = (item.HeapIndex - 1) / 2; // Calculate parent index
        
        // Loop to sort up the item in the heap
        while (true) {
            T parentItem = items[parentIndex]; // Get the parent item
            if (item.CompareTo(parentItem) > 0) { // Compare item with parent
                Swap(item, parentItem); // Swap if necessary
            }
            else {
                break; // Exit loop if item is in correct position
            }

            parentIndex = (item.HeapIndex - 1) / 2; // Update parent index
        }
    }

    // Swap two items in the heap
    void Swap(T itemA, T itemB) {
        items[itemA.HeapIndex] = itemB; // Update item A in the heap array
        items[itemB.HeapIndex] = itemA; // Update item B in the heap array
        int itemAIndex = itemA.HeapIndex; // Store item A's index
        itemA.HeapIndex = itemB.HeapIndex; // Swap item indices
        itemB.HeapIndex = itemAIndex; // Set item B's index to stored value of item A's index
    }
}

// Interface for items in the heap
public interface IHeapItem<T> : IComparable<T> {
    int HeapIndex { get; set; } // Property to get/set the index of an item in the heap
}
