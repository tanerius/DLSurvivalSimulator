#pragme once

#include<vector>
#include<random>

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
        float GetWeight(int inputIndex, int outputIndex)
        {
            return 0f;
        }

        float randomGen()
        {
            std::random_device rd;  // Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(-1.0, 1.001);
            float ret = dis(gen);
            if (ret > 1.000f)
                ret = 1f
                return ret;
        }

        void RandomizeWeights()
        {
            for (auto& w : m_weights) {
                w = randomGen();
            }
        }

    public:
        Level(int inputs, int outputs)
        {
            m_inputNeurons = inputs;
            m_outputNeurons = outputs;

            m_inputs.resize(m_inputNeurons, 0);
            m_outputs.resize(m_outputNeurons, 0);
            m_biases.resize(m_outputNeurons);

            m_weights.resize(m_inputNeurons * m_outputNeurons);

            for (auto& w : m_weights) {
                w = randomGen();
            }

            for (auto& b : m_biases) {
                b = randomGen();
            }
        }

        std::vector<int> FeedForward(const std::vector<int>& inputs)
        {
            for (int i = 0; i < inputs.size(); i++)
                m_inputs[i] = inputs[i];
            
            for (int i = 0; i < m_outputs.size(); i++)
            {
                float sum = 0;
                for (int j = 0; j < m_inputs.size(); j++)
                    sum += m_inputs[j] * GetWeight(j, i);

                if (sum > m_biases[i])
                    m_outputs[i] = 1;
                else
                    m_outputs[i] = 0;
            }

            return m_outputs;
        }
    };
}