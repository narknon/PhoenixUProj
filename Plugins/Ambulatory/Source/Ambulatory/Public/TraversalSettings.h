#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TraversalDetectionSettings.h"
#include "TraversalDropDownSettings.h"
#include "TraversalLadderSettings.h"
#include "TraversalMetricsSettings.h"
#include "TraversalSnappingSettings.h"
#include "TraversalSwimDiveSettings.h"
#include "TraversalSettings.generated.h"

UCLASS(Blueprintable)
class AMBULATORY_API UTraversalSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTraversalDetectionSettings GroundTraversalSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTraversalDetectionSettings JumpFallTraversalSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTraversalMetricsSettings MetricsSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTraversalSnappingSettings SnappingSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTraversalSwimDiveSettings SwimDiveSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTraversalLadderSettings LadderSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTraversalDropDownSettings DropDownSettings;
    
    UTraversalSettings();
};

