// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MobileFPS03 : ModuleRules
{
	public MobileFPS03(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
