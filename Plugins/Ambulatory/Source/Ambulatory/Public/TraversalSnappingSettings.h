#pragma once
#include "CoreMinimal.h"
#include "TraversalModeSnappingSettings.h"
#include "TraversalSnappingSettings.generated.h"

USTRUCT(BlueprintType)
struct AMBULATORY_API FTraversalSnappingSettings {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FTraversalModeSnappingSettings ModeSnappingSettings[16];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTraversalModeSnappingSettings JumpVaultSnappingSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTraversalModeSnappingSettings AutoTraversalSnappingSettings;
    
    FTraversalSnappingSettings();
};

