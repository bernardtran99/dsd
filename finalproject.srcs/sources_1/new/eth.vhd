library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity eth is
    port (
        CLK50MHZ : in std_logic;
        ETH_MDC : out std_logic;
        ETH_MDIO : inout std_logic;
        ETH_RSTN : out std_logic;
        ETH_CRSDV : inout std_logic;--bidirectional
        ETH_RXERR : 
        );
end eth;

architecture Behavioral of eth is

begin


end Behavioral;
