#ifndef RocketMath_H
#define RocketMath_H

// Algum motivo pra usar o .h? 
#include <stdint.h>
#include <string>
#include <memory>

// Melhor criar uma constante "const auto SIZE_OF_POWER_FUNC_RESULT 1024"
// Macros são mal vistas.
#define SIZE_OF_POWER_FUNC_RESULT           1024

// Não é muito costumeiro evitar o "std", pra mim não é um problema, mas
// acho que alguém possa achar estranho?
using std::string, std::shared_ptr;

class RocketMath
{

public:
    RocketMath();
    ~RocketMath();

    /**
     * Implementing the reverse of the number, e.i input 12345 output 54321.
     * @param base_number base number which will be reversed.
     * @return The reversed number.
     */
    uint32_t reverse_numbers(uint32_t base_number);
    
    /**
     * Calculate the power of given base and exponent number 
     * 
     * @param base number in the format of string of the operation.
     * @param exponent number in the format of c-string of the operation.
     * @param result  result of the operation in the format of c-string.
     * @return result if the operation was successful, where:
     *      0 - success
     *      1 - error 
     */
    // Dá uma olhada naquele livro que comentei sobre smart pointers. Nessa semântica aqui, dá impressão de que essa
    // classe vai participar do life time dessas strings. Então na verdade elas poderiam ser const std::shared_ptr<const string>&.
    // Inclusive, não existe nem necessidade imagino de usar shared pointers aqui, você pode usar const std::string& ou ainda
    // std::string_view (dá uma pesquiasada nesse depois)..
    // No parámetro "result", você pode usar uma std::string&. No geral dá pra evitar pointeiros estilo C sempre que possível.
    uint8_t power(const shared_ptr<const string> base, const shared_ptr<const string> exponent, shared_ptr<string> result);

    /**
     * Calculate the multiplication of given 2 numbers num_a*num_b
     * 
     * @param num_a first number
     * @param num_b second number
     * @param result return of operation
     */
    // Esse estilo de retorno que você tá usando é bem antigo, você pode fazer duas coisas:
    // Retornar um std::pair<Status, std::string> ou std::pair<bool, std::string>,
    // Ou um std::optional<std::string>.
    uint8_t multiply(const shared_ptr<const string> num_a, const shared_ptr<const string> num_b, shared_ptr<string> result);

    /**
     * Sum 2 values in c-string format.
     * @param num_a number to be part in the sum.
     * @param num_b number to be part in the sum.
     * @param result result of the sum.
     * 
     * @note This function doesn't handle negative values (FIXME)
     */
    void sum(const shared_ptr<const string> num_a, const shared_ptr<const string> num_b, shared_ptr<string> result);

private:

    /**
     * Inverte a given c-string i.e. "123456789" will be "987654321"
     * @param str_to_invert C-string to be inverted.
     */
    // Mesma coisa sobre o std::string&.
    void invert_string(shared_ptr<string> result);
};

#endif
