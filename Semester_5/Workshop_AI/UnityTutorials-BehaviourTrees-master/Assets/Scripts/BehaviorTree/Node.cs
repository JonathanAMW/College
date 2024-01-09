using System.Collections;
using System.Collections.Generic;


namespace BehaviorTree
{
    // Enum to represent the possible states of a behavior tree node.
    public enum NodeState
    {
        RUNNING,   // Node is currently executing or processing.
        SUCCESS,   // Node has completed its task successfully.
        FAILURE    // Node has completed its task unsuccessfully.
    }

    // Base class for behavior tree nodes.
    public class Node
    {
        protected NodeState state; // Represents the state of the node.
        public Node parent; // Reference to the parent node.
        protected List<Node> children = new List<Node>(); // List of child nodes.
        private Dictionary<string, object> _dataContext = new Dictionary<string, object>(); // Data storage for the node.

        // Default constructor for creating a node with no children.
        public Node()
        {
            parent = null;
        }

        // Constructor for creating a node with a list of child nodes.
        public Node(List<Node> children)
        {
            foreach (Node child in children)
                _Attach(child);
        }

        // Private method to attach a child node to the current node.
        private void _Attach(Node node)
        {
            node.parent = this;
            children.Add(node);
        }

        // Virtual method to be overridden by derived classes to evaluate node state.
        public virtual NodeState Evaluate() => NodeState.FAILURE;

        // Method to set data in the node's data context.
        public void SetData(string key, object value)
        {
            _dataContext[key] = value;
        }

        // Method to get data from the node's data context or parent nodes recursively.
        public object GetData(string key)
        {
            object value = null;
            if (_dataContext.TryGetValue(key, out value))
                return value;

            Node node = parent;
            while (node != null)
            {
                value = node.GetData(key);
                if (value != null)
                    return value;
                node = node.parent;
            }
            return null;
        }

        // Method to clear data from the node's data context or parent nodes recursively.
        public bool ClearData(string key)
        {
            if (_dataContext.ContainsKey(key))
            {
                _dataContext.Remove(key);
                return true;
            }

            Node node = parent;
            while (node != null)
            {
                bool cleared = node.ClearData(key);
                if (cleared)
                    return true;
                node = node.parent;
            }
            return false;
        }
    }
}

/*


namespace BehaviorTree
{
    public enum NodeState
    {
        RUNNING,
        SUCCESS,
        FAILURE
    }

    public class Node
    {
        protected NodeState state;

        public Node parent;
        protected List<Node> children = new List<Node>();

        private Dictionary<string, object> _dataContext = new Dictionary<string, object>();

        public Node()
        {
            parent = null;
        }
        public Node(List<Node> children)
        {
            foreach (Node child in children)
                _Attach(child);
        }

        private void _Attach(Node node)
        {
            node.parent = this;
            children.Add(node);
        }

        public virtual NodeState Evaluate() => NodeState.FAILURE;

        public void SetData(string key, object value)
        {
            _dataContext[key] = value;
        }

        public object GetData(string key)
        {
            object value = null;
            if (_dataContext.TryGetValue(key, out value))
                return value;

            Node node = parent;
            while (node != null)
            {
                value = node.GetData(key);
                if (value != null)
                    return value;
                node = node.parent;
            }
            return null;
        }

        public bool ClearData(string key)
        {
            if (_dataContext.ContainsKey(key))
            {
                _dataContext.Remove(key);
                return true;
            }

            Node node = parent;
            while (node != null)
            {
                bool cleared = node.ClearData(key);
                if (cleared)
                    return true;
                node = node.parent;
            }
            return false;
        }
    }

}
*/