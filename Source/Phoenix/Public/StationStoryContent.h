#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SceneRigStageCast.h"
#include "StationStoryAnimationContent.h"
#include "StationStoryContent.generated.h"

class USkeletalMesh;
class UStaticMesh;
class UStationStoryProp;

UCLASS(Blueprintable)
class UStationStoryContent : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStageCast StoryCast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStationStoryProp*> Props;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStationStoryAnimationContent> Enters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStationStoryAnimationContent> TransitionsIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStationStoryAnimationContent> Idles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStationStoryAnimationContent> TransitionsOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStationStoryAnimationContent> Exits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> StaticMeshProps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USkeletalMesh*> SkeletalMeshProps;
    
    UStationStoryContent();
};

