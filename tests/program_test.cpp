#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/link.hpp"
#include "../src/Node.hpp"

Link gold("Gold");
Link silver("Silver");
Link bronze ("Bronze");

Node node_one(gold);
Node node_two(silver, &node_one);
Node node_three(bronze, &node_two);

TEST_CASE( "Node 1 stores gold" ) {
    REQUIRE( node_one.content() == gold );
}
TEST_CASE( "Node 2 stores silver" ) {
    REQUIRE( node_two.content() == silver );
}
TEST_CASE( "Node 3 stores bronze" ) {
    REQUIRE( node_three.content() == bronze );
}
TEST_CASE( "Node 1's next returns node 2's silver" ) {
    REQUIRE( node_one.next().content() == silver);
}
TEST_CASE( "Node 2's next returns node 3's Bronze" ) {
    REQUIRE( node_two.next().content() == bronze );
}
TEST_CASE( "Nodes 1's next's next's returns node's bronze" ) {
    REQUIRE( node_one.next().next().content() == bronze );
}
TEST_CASE( "Nodes can be traveresed like a list." ) {
    // you can make a bunch of nodes and have them store other (non-Link class) stuff.
    Node node_A('A');
    Node node_B('B', &node_A);
    Node node_C('C', &node_B);
    Node node_D('D', &node_C);
    Node node_E('E', &node_D);
    Node node_F('F', &node_E);
    Node node_G('G', &node_F);
    // then traverse them as a list
    Node<char> *char_node_pointer_iterator = &node_A;
    REQUIRE( char_node_pointer_iterator->content() == 'A');
    *char_node_pointer_iterator = char_node_pointer_iterator->next();
    REQUIRE( char_node_pointer_iterator->content() == 'B');
    *char_node_pointer_iterator = char_node_pointer_iterator->next();
    REQUIRE( char_node_pointer_iterator->content() == 'C');
    *char_node_pointer_iterator = char_node_pointer_iterator->next();
    REQUIRE( char_node_pointer_iterator->content() == 'D');
    *char_node_pointer_iterator = char_node_pointer_iterator->next();
    REQUIRE( char_node_pointer_iterator->content() == 'E');
    *char_node_pointer_iterator = char_node_pointer_iterator->next();
    REQUIRE( char_node_pointer_iterator->content() == 'F');
    *char_node_pointer_iterator = char_node_pointer_iterator->next();
    REQUIRE( char_node_pointer_iterator->content() == 'G');
}