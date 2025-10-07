// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InputDataConfig.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECT_InputDataConfig_generated_h
#error "InputDataConfig.generated.h already included, missing '#pragma once' in InputDataConfig.h"
#endif
#define PROJECT_InputDataConfig_generated_h

#define FID_Project_Source_Project_InputDataConfig_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInputDataConfig(); \
	friend struct Z_Construct_UClass_UInputDataConfig_Statics; \
public: \
	DECLARE_CLASS(UInputDataConfig, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Project"), NO_API) \
	DECLARE_SERIALIZER(UInputDataConfig)


#define FID_Project_Source_Project_InputDataConfig_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInputDataConfig(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UInputDataConfig(UInputDataConfig&&); \
	UInputDataConfig(const UInputDataConfig&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInputDataConfig); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInputDataConfig); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInputDataConfig) \
	NO_API virtual ~UInputDataConfig();


#define FID_Project_Source_Project_InputDataConfig_h_13_PROLOG
#define FID_Project_Source_Project_InputDataConfig_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_Source_Project_InputDataConfig_h_16_INCLASS_NO_PURE_DECLS \
	FID_Project_Source_Project_InputDataConfig_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_API UClass* StaticClass<class UInputDataConfig>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_Source_Project_InputDataConfig_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
