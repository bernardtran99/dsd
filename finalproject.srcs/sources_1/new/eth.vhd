library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity eth is
    port (
        -- all ports that are connected to ethernet module
        -- some may not be used
        clk_in : in STD_LOGIC;
        ETH_MDC : out std_logic;
        ETH_MDIO : inout std_logic;
        ETH_RSTN : out std_logic;
        ETH_CRSDV : in std_logic;
        ETH_RXERR : in std_logic;
        ETH_RXD : in std_logic_vector (1 downto 0);
        ETH_TXEN : out std_logic;
        ETH_TXD : out std_logic_vector (1 downto 0);
        ETH_REFCLK : out std_logic;
        ETH_INTN : inout std_logic
        );
end eth;

architecture Behavioral of eth is
    
    -- clock component
    component clk_wiz_0 is
    port (
      clk_in1  : in std_logic;
      clk_out1 : out std_logic
    );
    end component;
    
begin
    
    -- this is the 2 bit data packet that is going to be transmitted
    ETH_TXD <= "01010101";
    
    -- set to high to set transit enable
    ETH_TXEN <= '1';
    
    -- init clock for ETH_REFCLK and ETH_MDC
    clk_wiz_0_inst : clk_wiz_0
    port map (
      clk_in1 => clk_in,
      clk_out1 => ETH_REFCLK
    );
    
end Behavioral;
