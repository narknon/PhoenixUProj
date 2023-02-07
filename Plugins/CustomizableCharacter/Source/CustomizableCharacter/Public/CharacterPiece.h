#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "CharacterPieceCharacterClassification.h"
#include "CharacterPieceNiagaraSystem.h"
#include "CharacterPieceType.h"
#include "ECharacterPieceGenderEnum.h"
#include "EGloveTypeEnum.h"
#include "EHatTypeEnum.h"
#include "EPantLengthEnum.h"
#include "ERobeShoulderTypeEnum.h"
#include "ERobeTypeEnum.h"
#include "EShoeHeightEnum.h"
#include "ESleeveLengthEnum.h"
#include "MaterialOverride.h"
#include "MeshOverride.h"
#include "Templates/SubclassOf.h"
#include "CharacterPiece.generated.h"

class UAnimInstance;
class UPoseAsset;
class USkeletalMesh;

UCLASS(Blueprintable)
class CUSTOMIZABLECHARACTER_API UCharacterPiece : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterPieceCharacterClassification CharacterClassification;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterPieceType CharacterPieceType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECharacterPieceGenderEnum Gender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESleeveLengthEnum SleeveLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHatTypeEnum HatType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EShoeHeightEnum ShoeHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPantLengthEnum PantLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERobeTypeEnum RobeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGloveTypeEnum GloveType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERobeShoulderTypeEnum RobeShoulderType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* DefaultMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPoseAsset* FacialPoseAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMeshOverride> MeshOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialOverride> MaterialOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> RegionNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCharacterPieceNiagaraSystem> NiagaraSystems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> AnimClass;
    
    UCharacterPiece();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName ToId() const;
    
};

