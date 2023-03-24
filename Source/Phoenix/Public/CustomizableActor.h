#pragma once
#include "CoreMinimal.h"
#include "CustomizableCharacterInterface.h"
#include "DbDoubleColumnInfo.h"
#include "GameFramework/Actor.h"
#include "LODBudgeterInterface.h"
#include "SignificanceInterface.h"
#include "CustomizableActor.generated.h"

class UCustomizableCharacterComponent;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ACustomizableActor : public AActor, public ICustomizableCharacterInterface, public ISignificanceInterface, public ILODBudgeterInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbDoubleColumnInfo CharacterIdInfo;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterComponent* CCC;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* Mesh;
    
public:
    ACustomizableActor(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void SetLODOverride(int32 InLODOverride);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetRegistryID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCustomizableCharacterComponent* GetCCC() const;
    
    
    // Fix for true pure virtual functions not being implemented
};

