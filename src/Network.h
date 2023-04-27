#pragma once

#include<vector>

namespace DLS
{
    class Level
    {
    private:
        int m_inputNeurons;
        int m_outputNeurons;
        std::vector<int> m_inputs;
        std::vector<int> m_outputs;
        
        /// <summary>
        /// A bias is a value which defines the 
        /// threshold when a neuron should fire
        /// </summary>
        std::vector<float> m_biases; // same size as output

        /// <summary>
        /// Weights of the connections between input and output neurons.
        /// threshold when a neuron should fire
        /// </summary>
        std::vector<float> m_weights; // inputs x outputs

        /// <summary>
        /// A method to get the value of a specific weight. 
        /// Since they are stored in a signle dimentional vector, this is just 
        /// a helper method.
        /// </summary>
        /// <param name="inputIndex">For which input</param>
        /// <param name="outputIndex">To which output</param>
        /// <returns></returns>
        float GetWeight(const int inputIndex, const int outputIndex) const;

        /// <summary>
        /// Generate a random float from -1,1
        /// </summary>
        float randomGen() const;

        /// <summary>
        /// A method to set the value of a specific weight. 
        /// Since they are stored in a signle dimentional vector, this is just 
        /// a helper method.
        /// </summary>
        /// <param name="inputIndex">For which input</param>
        /// <param name="outputIndex">To which output</param>
        /// <param name="value">Value to set to</param>
        void SetWeight(const int inputIndex, const int outputIndex, const float value);

    public:
        Level(int inputs, int outputs);

        std::vector<int> FeedForward(const std::vector<int>& inputs);
    };


    class Network
    {
        public:
        Network() = delete;
        Network(const std::vector<int>& neuronCounts);
        std::vector<int> FeedForward(int level, std::vector<int> inputs);

        private:
        std::vector<Level*> m_levels;
        std::vector<int> m_outputs;
    };


}