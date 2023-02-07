#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "DbDoubleColumnInfo.h"
#include "DbSingleColumnInfo.h"
#include "SceneRigParticipant.h"
#include "Actor_FromT3Pool.generated.h"

class UStringProvider;
class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UActor_FromT3Pool : public UActorProvider, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseBoundParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStringProvider* ActorDbIdProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbDoubleColumnInfo CharacterIdInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo CharacterLookIdInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* PlacementLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartWithoutActors;
    
    UActor_FromT3Pool();
    
    // Fix for true pure virtual functions not being implemented
};

