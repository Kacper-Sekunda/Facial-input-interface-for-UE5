// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project/InputDataConfig.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInputDataConfig() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
PROJECT_API UClass* Z_Construct_UClass_UInputDataConfig();
PROJECT_API UClass* Z_Construct_UClass_UInputDataConfig_NoRegister();
UPackage* Z_Construct_UPackage__Script_Project();
// End Cross Module References

// Begin Class UInputDataConfig
void UInputDataConfig::StaticRegisterNativesUInputDataConfig()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInputDataConfig);
UClass* Z_Construct_UClass_UInputDataConfig_NoRegister()
{
	return UInputDataConfig::StaticClass();
}
struct Z_Construct_UClass_UInputDataConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "InputDataConfig.h" },
		{ "ModuleRelativePath", "InputDataConfig.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Move_MetaData[] = {
		{ "Category", "InputDataConfig" },
		{ "ModuleRelativePath", "InputDataConfig.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Look_MetaData[] = {
		{ "Category", "InputDataConfig" },
		{ "ModuleRelativePath", "InputDataConfig.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Move;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Look;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInputDataConfig>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInputDataConfig_Statics::NewProp_Move = { "Move", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInputDataConfig, Move), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Move_MetaData), NewProp_Move_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInputDataConfig_Statics::NewProp_Look = { "Look", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInputDataConfig, Look), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Look_MetaData), NewProp_Look_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInputDataConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInputDataConfig_Statics::NewProp_Move,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInputDataConfig_Statics::NewProp_Look,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInputDataConfig_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UInputDataConfig_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInputDataConfig_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInputDataConfig_Statics::ClassParams = {
	&UInputDataConfig::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UInputDataConfig_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UInputDataConfig_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInputDataConfig_Statics::Class_MetaDataParams), Z_Construct_UClass_UInputDataConfig_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UInputDataConfig()
{
	if (!Z_Registration_Info_UClass_UInputDataConfig.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInputDataConfig.OuterSingleton, Z_Construct_UClass_UInputDataConfig_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInputDataConfig.OuterSingleton;
}
template<> PROJECT_API UClass* StaticClass<UInputDataConfig>()
{
	return UInputDataConfig::StaticClass();
}
UInputDataConfig::UInputDataConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UInputDataConfig);
UInputDataConfig::~UInputDataConfig() {}
// End Class UInputDataConfig

// Begin Registration
struct Z_CompiledInDeferFile_FID_Project_Source_Project_InputDataConfig_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInputDataConfig, UInputDataConfig::StaticClass, TEXT("UInputDataConfig"), &Z_Registration_Info_UClass_UInputDataConfig, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInputDataConfig), 3803354710U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_Source_Project_InputDataConfig_h_2024946963(TEXT("/Script/Project"),
	Z_CompiledInDeferFile_FID_Project_Source_Project_InputDataConfig_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_Source_Project_InputDataConfig_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
