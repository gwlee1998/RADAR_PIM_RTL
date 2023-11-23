always@(*)
begin
	target_node = 0;
	if (0)
		;
	else if ($unsigned(addr[31:19])==(32'h 800))
		target_node = `NODE_ID_I_SNIM_I_TEST1_SLAVE;
	else if ($unsigned(addr[31:18])==(32'h 1002))
		target_node = `NODE_ID_I_SNIM_I_SYSTEM_SRAM_NO_NAME;
	else if ($unsigned(addr[31:16])==(32'h e000))
		target_node = `NODE_ID_I_SNIM_COMMON_PERI_GROUP_NO_NAME;
	else if ($unsigned(addr[31:18])==(32'h 3840))
		target_node = `NODE_ID_I_SNIM_PLATFORM_CONTROLLER_NO_NAME;
	else if ($unsigned(addr[31:16])==(32'h e104))
		target_node = `NODE_ID_I_SNIM_EXTERNAL_PERI_GROUP_NO_NAME;
	else if ($unsigned(addr[31:12])==(32'h f0000))
		target_node = `NODE_ID_CORE_PERI_GROUP_NO_NAME;
	else
		target_node = `NODE_ID_DEFAULT_SLAVE;
end