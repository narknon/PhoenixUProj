#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CharacterBoneProjection.h"
#include "CharacterBoneProjectionParams.h"
#include "CharacterBoneProjectionResults.h"
#include "CharacterBoneProjectionState.h"
#include "SimpleBoneInfoCache.h"
#include "CharacterBoneProjector.generated.h"

class AActor;

UCLASS(Blueprintable)
class UCharacterBoneProjector : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCharacterBoneProjection> Projections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCharacterBoneProjectionState> ProjectionStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterBoneProjectionParams ProjectionParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterBoneProjectionResults ProjectionResults;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSimpleBoneInfoCache BoneCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bStatesInitialized;
    
public:
    UCharacterBoneProjector();
    UFUNCTION(BlueprintCallable)
    void Update(AActor* Owner, float dt);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool StatesInitialized() const;
    
    UFUNCTION(BlueprintCallable)
    bool InitializeState(AActor* Owner);
    
};

