#pragma once
#include "CoreMinimal.h"
#include "CharacterPieceType.h"
#include "SceneRigObjectActionBase.h"
#include "USceneAction_ResetClothSim_ClothingTeleportMode.h"
#include "SceneAction_ResetClothSim.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ResetClothSim : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPiecesListIsInclusive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCharacterPieceType> PiecesList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneAction_ResetClothSim_ClothingTeleportMode ClothTeleportMode;
    
    USceneAction_ResetClothSim();
};

