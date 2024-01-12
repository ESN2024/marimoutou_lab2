library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity toplevel is
	port (
		CLK      : in  std_logic                    := '0'; --   clk.clk
		RESET : in  std_logic                    := '0'; -- reset.reset_n
		SEG1   : out std_logic_vector(7 downto 0)         --  seg1.export
	);
end entity toplevel;

architecture rtl of toplevel is

	component lab2 is
		port (
			clk_clk       : in  std_logic                    := 'X'; -- clk
			reset_reset_n : in  std_logic                    := 'X'; -- reset_n
			seg1_export   : out std_logic_vector(3 downto 0)         -- export
		);
	end component lab2;
	
	component BCD7SEG is
		port (
			input : in std_logic_vector(3 downto 0) := (others => 'X'); 
			output : out std_logic_vector(7 downto 0)
		);
	end component BCD7SEG;
	
signal segment1 : std_logic_vector(3 downto 0);

begin

	u0 : component lab2
		port map (
			clk_clk       => CLK,       --   clk.clk
			reset_reset_n => RESET, -- reset.reset_n
			seg1_export   => segment1    --  seg1.export
		);
		
	u1 : component BCD7SEG
		port map (
			input => segment1,
			output => SEG1
		);

end architecture;